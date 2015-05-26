#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "stm8s.h"
#include "lib.h"
#include "coroutine.h"

char uartstr[16] = { 0 };
const uint8_t uartstr_len = 12;
volatile uint8_t pos = 0;

volatile uint8_t I2C_ReadByte_Result_Addr = 0;
volatile uint8_t I2C_ReadByte_Result_Reg = 0;
volatile uint8_t I2C_ReadByte_Result_Ready = 1;
volatile uint8_t I2C_ReadByte_Result_Value = 0;

void irq_i2c (void) __interrupt(IRQ_I2C) {
    static uint8_t Temp, Byte_Read;

    scr_begin;

    while (I2C_ReadByte_Result_Ready) {
        scr_return_void;
    }

    // while((I2C_SR3 & 0x02) != 0);

    while ((I2C_SR1 & 0x01) == 0) { //Start condition generated
        scr_return_void;
    }

    I2C_DR = (I2C_ReadByte_Result_Addr << 1);         //Device address
    // if ((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)
    while ((I2C_SR1 & 0x02) == 0) { //Address sent
        scr_return_void;
    }
    Temp = I2C_SR3;        //Status register

    I2C_DR = I2C_ReadByte_Result_Reg;         //Device register
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

    I2C_DR = ((I2C_ReadByte_Result_Addr << 1) | 0x01);    //Device address(read)
    while ((I2C_SR1 & 0x02) == 0) { //Address sent
     scr_return_void;
    }
    Temp = I2C_SR3;        //Status register

    // Reading
    // I2C_CR2 |= 0x04;        //I2C Ack Condition
    // while((I2C_SR1 & 0x40) == 0); //Byte transfer finished
    // HighByteRead = 0x00;      //Clean data
    // HighByteRead = I2C_DR;     //Byte 1

    I2C_CR2 |= 0x02;        //I2C Stop Condition

    while ((I2C_SR1 & 0x40) == 0) { //Byte transfer finished
      scr_return_void;
    }
    // Byte_Read = 0x00;        //Clean data
    I2C_ReadByte_Result_Value = I2C_DR;

    I2C_ReadByte_Result_Ready = 1;

    scr_finish_void;
}

void i2c_read_byte (uint8_t addr, uint8_t reg) {
    I2C_ReadByte_Result_Addr = addr;
    I2C_ReadByte_Result_Reg = reg;
    I2C_ReadByte_Result_Ready = 0;
    I2C_CR2 |= 0x01;        //I2C Start Condition
}

uint8_t i2c_read_byte_result () {
    return I2C_ReadByte_Result_Ready ? 0 : 1;
}

void write_chars (char* to, uint8_t val) {
    uint8_t high = val >> 4;
    uint8_t low = val & 0xf;
    to[0] = high > 0x9 ? 0x61 + (high - 0xa) : 0x30 + high;
    to[1] = low > 0x9 ? 0x61 + (low - 0xa) : 0x30 + low;
}

volatile int doread = 0;

void uart_tx (void) __interrupt(IRQ_UART1) {
    if (uart_tx_complete()) {
        if (pos < uartstr_len) {
            uart_write(uartstr[pos]);
            ++pos;
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

void uart_rx (void) __interrupt(IRQ_UART1_FULL) {
    scr_begin;
    
    while (1) {
        input_byte = USART1_DR;
        if (input_byte != 'R') {
            scr_return_void;
        }
        break;
    }
    scr_return_void;

    input_byte = USART1_DR;
    doread = 1;

    scr_finish_void;

    //     uart_write(uartstr[0]);
    //     uart_write(uartstr[1]);
    //     uart_write(uartstr[2]);
    //     uart_write(uartstr[3]);
    // }
}


void irq_timer2 (void) __interrupt(IRQ_TIM2) {
    //  Reset the interrupt otherwise it will fire again straight away.
    TIM2_SR1->UIF = 0;
}

//
//  Main program loop.
//
void main (void) {
    volatile uint8_t a;
    uint8_t regread;
    int32_t c;
    int32_t f;

    __disable_interrupt();
    init_clock();
    init_timer2();
    init_i2c();
    config_ports();
    config_timer2();
    config_uart();
    gpio_write(0, 0);

    a = USART1_DR;
    __enable_interrupt();

    // 
    // uart_write('A');
    while (1) {

        // uart_write(celsval);
        __wait_for_interrupt();

        if (doread) {
            // looper();
            doread = 0;
            // uart_write(uartstr[0]);
            // uart_write('!');
            // gpio_write(0, gpio_read(0));

            i2c_read_byte(0x1D, input_byte);
            while (i2c_read_byte_result()) {
                __wait_for_interrupt();
            }

            uartstr[0] = I2C_ReadByte_Result_Value;

            // if (regread == 0x2A) {
                pos = 0;
                UART1_CR2->TCIEN = 1;
            // }
        }

        //     doread = 0;
        //     pos = 0;



            // c = ((17572 * tempraw) >> 16) - 4685;
            // f = (1.8 * c) + 3200;

            // write_chars(&uartstr[0], ((uint8_t*) &c)[3]);
            // write_chars(&uartstr[2], ((uint8_t*) &c)[2]);
            // write_chars(&uartstr[4], ((uint8_t*) &c)[1]);
            // write_chars(&uartstr[6], ((uint8_t*) &c)[0]);
        // }

        // if (uart_rx_available()) {
        //     volatile uint8_t a = USART1_DR;
            // gpio_write(0, 1);
        // }
    }
}
