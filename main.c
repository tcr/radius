#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "stm8s.h"
#include "lib.h"
#include "coroutine.h"

volatile uint8_t uartstr[16] = { 0 };
volatile uint8_t uartstr_len = 12;
volatile uint8_t uartstr_index = 0;

volatile uint8_t i2c_static_addr = 0;
volatile uint8_t i2c_static_reg = 0;
volatile uint8_t i2c_static_ready = 1;
volatile uint8_t i2c_static_value[32] = { 0 };
volatile uint8_t i2c_static_count = 0;
volatile uint8_t i2c_static_index = 0;

void irq_i2c (void) __interrupt(IRQ_I2C) {
    static uint8_t Temp, Byte_Read;

    scr_begin;

    while (i2c_static_ready) {
        scr_return_void;
    }

    // while((I2C_SR3 & 0x02) != 0);

    while ((I2C_SR1 & 0x01) == 0) { //Start condition generated
        scr_return_void;
    }

    I2C_DR = (i2c_static_addr << 1);         //Device address
    // if ((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)
    while ((I2C_SR1 & 0x02) == 0) { //Address sent
        scr_return_void;
    }
    Temp = I2C_SR3;        //Status register

    I2C_DR = i2c_static_reg;         //Device register
    while ((I2C_SR1 & 0x80) == 0) { //Data register empty (transmitters)
        scr_return_void;
    }

    // Writing
    // I2C_DR = Data;         //Device data
    // while((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)
    // I2C_CR2 |= 0x02;        //I2C Stop Condition
    // This might be wrong; other code used a wait?
    // while ((I2C_SR1 & 0x40) == 0) { //Byte transfer finished
    //   scr_return_void;
    // }
    // i = 0xFFFF;
    // while(i--);
    // scr_finish_void;

    I2C_CR2 |= 0x01;        //I2C Start Condition
    while ((I2C_SR1 & 0x01) == 0) { //Start condition generated
        scr_return_void;
    }

    I2C_DR = ((i2c_static_addr << 1) | 0x01);    //Device address(read)
    while ((I2C_SR1 & 0x02) == 0) { //Address sent
     scr_return_void;
    }
    Temp = I2C_SR3;        //Status register

    // Reading
    // I2C_CR2 |= 0x04;        //I2C Ack Condition
    // while((I2C_SR1 & 0x40) == 0); //Byte transfer finished
    // HighByteRead = 0x00;      //Clean data
    // HighByteRead = I2C_DR;     //Byte 1

    if (i2c_static_count > 1) {
        I2C_CR2 = 0x04;        //I2C Ack Condition
    }

    while (i2c_static_count > 0) {
        if (i2c_static_count == 1) {
            I2C_CR2 = 0x02;        //I2C Stop Condition
        }

        while ((I2C_SR1 & 0x40) == 0) { //Byte transfer finished
          scr_return_void;
        }
        // Byte_Read = 0x00;        //Clean data
        i2c_static_value[i2c_static_index++] = I2C_DR;

        --i2c_static_count;
    }

    i2c_static_ready = 1;

    scr_finish_void;
}

void i2c_read_bytes (uint8_t addr, uint8_t reg, size_t count) {
    i2c_static_addr = addr;
    i2c_static_reg = reg;
    i2c_static_ready = 0;
    i2c_static_count = count;
    i2c_static_index = 0;
    I2C_CR2 |= 0x01;        //I2C Start Condition
}

uint8_t i2c_read_byte_result () {
    return i2c_static_ready ? 0 : 1;
}

void write_chars (char* to, uint8_t val) {
    uint8_t high = val >> 4;
    uint8_t low = val & 0xf;
    to[0] = high > 0x9 ? 0x61 + (high - 0xa) : 0x30 + high;
    to[1] = low > 0x9 ? 0x61 + (low - 0xa) : 0x30 + low;
}

typedef enum {
    LOOP_SKIP,
    LOOP_ACTION,
} loopstate_t;

volatile loopstate_t loop_state = LOOP_SKIP;

void uart_tx (void) __interrupt(IRQ_UART1) {
    if (uart_tx_complete()) {
        if (uartstr_index < uartstr_len) {
            uart_write(uartstr[uartstr_index]);
            ++uartstr_index;
        } else {
            // UART1_CR2->TCIEN = 1;
            gpio_write(0, 1);
            // UART1_CR2->TIEN = 0; 
            UART1_CR2->TCIEN = 0;
        }
    }
    // if (UART1_CR2->TCIEN && uart_tc_complete()) {
    //     UART1_CR2->TCIEN = 0;
    //     UART1_CR2->TEN = 0;
    // }
}

volatile uint8_t input_byte = 0;
volatile uint8_t input_byte_count = 0;

void uart_rx (void) __interrupt(IRQ_UART1_FULL) {
    scr_begin;

    // Wait until a leading 'R' character.
    while (1) {
        input_byte = USART1_DR;
        if (input_byte != 'R') {
            scr_return_void;
        }
        break;
    }
    scr_return_void;

    // Read the input byte.
    input_byte = USART1_DR;
    scr_return_void;

    // Read the count.
    input_byte_count = USART1_DR;

    // Change looping state.
    loop_state = LOOP_ACTION;

    scr_finish_void;
}


void irq_timer2 (void) __interrupt(IRQ_TIM2) {
    //  Reset the interrupt otherwise it will fire again straight away.
    TIM2_SR1->UIF = 0;
}

void main (void) {
    __disable_interrupt();
    init_clock();
    init_timer2();
    init_i2c();
    config_ports();
    config_timer2();
    config_uart();
    gpio_write(0, 0);
    __enable_interrupt();

    while (1) {
        __wait_for_interrupt();

        if (loop_state == LOOP_ACTION) {
            loop_state = LOOP_SKIP;

            // Assume this is an I2C action.
            i2c_read_bytes(0x1D, input_byte, input_byte_count);
            while (i2c_read_byte_result()) {
                __wait_for_interrupt();
            }

            // Manually copy over response.
            uartstr[0] = 'r';
            uartstr[1] = i2c_static_value[0];
            uartstr[2] = i2c_static_value[1];
            uartstr[3] = i2c_static_value[2];
            uartstr[4] = i2c_static_value[3];
            uartstr[5] = i2c_static_value[4];
            uartstr[6] = i2c_static_value[5];

            // Restart transmission.
            uartstr_index = 0;
            UART1_CR2->TCIEN = 1;
        }
    }
}
