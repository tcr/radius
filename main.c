#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "stm8s.h"
#include "lib.h"


char uartstr[16] = "Tessel Tag\r\n";
const uint8_t uartstr_len = 12;
volatile uint8_t pos = 0;






void I2C_Init(void);
void I2C_Write(uint8_t Addr, uint8_t Reg, uint8_t Data);
void i2c_read_byte(uint8_t Addr, uint8_t Reg);
uint16_t I2C_ReadWord(uint8_t Addr, uint8_t Reg);

void I2C_Init(void)
{
 I2C_CR1 = 0x00; //Disable I2C
 I2C_CR2 = 0x04; //Acknowledge enable

 // Program the peripheral input clock in I2C_FREQR Register in order to generate correct timings.
 I2C_FREQR = 10; //Peripheral clock frequency = 1~24mHz

 // Configure the rise time register
// I2C_OARH = 0x40; //Addressing mode = 10-bit slave address (7-bit address not acknowledged)
 I2C_OARH = 0x00; //Addressing mode = 7-bit slave address (10-bit address not acknowledged)
 I2C_OARL = 0x00; //Interface address
 I2C_ITR = 0x06; //Interrupt register

 // Configure the clock control registers
 I2C_CCRH = 0x80; //I2C master mode selection = Fast mode I2C
 I2C_CCRL = 30;  //Clock control register (Master mode)

 // Program the I2C_CR1 register to enable the peripheral
 I2C_CR1 = 0x01; //Enable I2C
}

void I2C_Write(uint8_t Addr, uint8_t Reg, uint8_t Data)
{
 uint8_t Temp;
 uint32_t  i;

 I2C_CR2 |= 0x01;        //I2C Start Condition
 while((I2C_SR1 & 0x01) == 0);  //Start condition generated

 I2C_DR = Addr;         //Device address(write)
 while((I2C_SR1 & 0x02) == 0); //Address sent
 Temp = I2C_SR3;        //Status register

 I2C_DR = Reg;         //Device register
 while((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)

 I2C_DR = Data;         //Device data
 while((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)

 I2C_CR2 |= 0x02;        //I2C Stop Condition
 i = 0xFFFF;
 while(i--);
}

#define scr_begin         static int scrLine = 0; switch(scrLine) { case 0:;
#define scr_finish(z)     } scrLine = 0; return (z)
#define scr_finish_void   } scrLine = 0; return

#define scr_return(z)     \
        do {\
            scrLine=__LINE__;\
            return (z); case __LINE__:;\
        } while (0)
#define scr_return_void       \
        do {\
            scrLine=__LINE__;\
            return; case __LINE__:;\
        } while (0)

volatile uint8_t I2C_ReadByte_Result_Addr = 0;
volatile uint8_t I2C_ReadByte_Result_Reg = 0;
volatile uint8_t I2C_ReadByte_Result_Ready = 1;
volatile uint8_t I2C_ReadByte_Result_Value = 0;


void I2C_ReadByte_Inner(void)
{
 static uint8_t Temp, Byte_Read;

 scr_begin;

 while (I2C_ReadByte_Result_Ready) {
    scr_return_void;
 }

 // while((I2C_SR3 & 0x02) != 0);

 // uartstr[0]++;
 
 while ((I2C_SR1 & 0x01) == 0) { //Start condition generated
     scr_return_void;
 }

 // uartstr[0]++;
 
 I2C_DR = I2C_ReadByte_Result_Addr;         //Device address
 // if ((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)
 while ((I2C_SR1 & 0x02) == 0) { //Address sent
     scr_return_void;
 }
 Temp = I2C_SR3;        //Status register

 // uartstr[0]++;
 
 I2C_DR = I2C_ReadByte_Result_Reg;         //Device register
 while ((I2C_SR1 & 0x80) == 0) { //Data register empty (transmitters)
     scr_return_void;
 }

 // uartstr[0]++;

 I2C_CR2 |= 0x01;        //I2C Start Condition
 while ((I2C_SR1 & 0x01) == 0) { //Start condition generated
     scr_return_void;
 }

 // uartstr[0]++;

 I2C_DR = (I2C_ReadByte_Result_Addr | 0x01);    //Device address(read)
 while ((I2C_SR1 & 0x02) == 0) { //Address sent
     scr_return_void;
 }
 Temp = I2C_SR3;        //Status register
 
 // uartstr[0]++;

 I2C_CR2 |= 0x02;        //I2C Stop Condition
 
 // uartstr[0]++;

 while ((I2C_SR1 & 0x40) == 0) { //Byte transfer finished
     scr_return_void;
 }
 // Byte_Read = 0x00;        //Clean data
 I2C_ReadByte_Result_Value = I2C_DR;

// uartstr[0]++;

 I2C_ReadByte_Result_Ready = 1;
 // I2C_ReadByte_Result_Value = Byte_Read;

 // return Byte_Read;
 scr_finish_void;
}

void i2c_read_byte (uint8_t addr, uint8_t reg) {
    I2C_ReadByte_Result_Addr = addr;
    I2C_ReadByte_Result_Reg = reg;
    I2C_ReadByte_Result_Ready = 0;
    I2C_CR2 |= 0x01;        //I2C Start Condition
}

uint8_t i2c_read_byte_result (uint8_t* result) {
    if (I2C_ReadByte_Result_Ready) {
        *result = I2C_ReadByte_Result_Value;
    }
    return I2C_ReadByte_Result_Ready ? 0 : 1;
}

uint16_t I2C_ReadWord(uint8_t Addr, uint8_t Reg)
{
 uint8_t Temp, HighByteRead, LowByteRead;
 uint16_t WordRead;

 uartstr[0] = 'U';
 
 I2C_CR2 |= 0x01;        //I2C Start Condition
 while((I2C_SR1 & 0x01) == 0); //Start condition generated
 
 uartstr[0] = 'V';

 I2C_DR = Addr;         //Device address
 while((I2C_SR1 & 0x02) == 0); //Address sent
 Temp = I2C_SR3;        //Status register

 uartstr[0] = 'W';
 
 I2C_DR = Reg;         //Device register
 while((I2C_SR1 & 0x80) == 0); //Data register empty (transmitters)

 uartstr[0] = 'X';
 
 I2C_CR2 |= 0x01;        //I2C Start Condition
 while((I2C_SR1 & 0x01) == 0); //Start condition generated

 uartstr[0] = 'Y';
 
 I2C_DR = (Addr | 0x01);    //Device address(read)
 while((I2C_SR1 & 0x02) == 0); //Address sent
 Temp = I2C_SR3;        //Status register

 uartstr[0] = 'Z';

 I2C_CR2 |= 0x04;        //I2C Ack Condition

 uartstr[0] = 'A';
 
 while((I2C_SR1 & 0x40) == 0); //Byte transfer finished
 HighByteRead = 0x00;      //Clean data
 HighByteRead = I2C_DR;     //Byte 1

 uartstr[0] = 'B';
 
 I2C_CR2 |= 0x02;        //I2C Stop Condition

 uartstr[0] = 'C';
  
 while((I2C_SR1 & 0x40) == 0); //Byte transfer finished
 LowByteRead = 0x00;       //Clean data
 LowByteRead = I2C_DR;     //Byte2

 uartstr[0] = 'D';
 
 WordRead = (LowByteRead | (HighByteRead << 8));
 return WordRead;
}

void write_chars (char* to, uint8_t val) {
    uint8_t high = val >> 4;
    uint8_t low = val & 0xf;
    to[0] = high > 0x9 ? 0x61 + (high - 0xa) : 0x30 + high;
    to[1] = low > 0x9 ? 0x61 + (low - 0xa) : 0x30 + low;
}

volatile int doread = 0;

void uart_timer (void) __interrupt(IRQ_UART1) {
    volatile uint8_t a;
    // return;
        // gpio_write(0, 1);
    if (uart_tx_complete()) {
        // gpio_write(0, 1);
        if (pos < uartstr_len) {
            uart_write(uartstr[pos]);
            ++pos;
        }
    }
    if (uart_tc_complete()) {
        // gpio_write(0, 0);
        // UART1_CR2->TEN = 0;
        uart_write('!');
        UART1_CR2->TEN = 0;
    }
    if (uart_rx_available()) {
        a = USART1_DR;
    //     uart_write(uartstr[0]);
    //     uart_write(uartstr[1]);
    //     uart_write(uartstr[2]);
    //     uart_write(uartstr[3]);
    }
}


void irq_timer2 (void) __interrupt(IRQ_TIM2) {
    doread = 1;
    //  Reset the interrupt otherwise it will fire again straight away.
    TIM2_SR1->UIF = 0;
}


void irq_i2c (void) __interrupt(IRQ_I2C) {

    I2C_ReadByte_Inner();
}

void looper (void) {
    scr_begin;
    gpio_write(0, 1);
    scr_return_void;
    gpio_write(0, 0);
    scr_finish_void;
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
    I2C_Init();
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
            gpio_write(0, gpio_read(0));
            // looper();

            doread = 0;
            // uart_write('!');

            i2c_read_byte(0x3A, 0x0D);
            while (i2c_read_byte_result(&regread)) {
                __wait_for_interrupt();
            }

            if (regread == 0x2A) {
                if (pos >= uartstr_len) {
                    pos = 0;
                    UART1_CR2->TEN = 1;
                    // uart_write(uartstr[0]);
                    // pos = 1;
                }
            }
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
