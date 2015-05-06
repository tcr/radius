#ifndef __LIB_H__
#define __LIB_H__

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "stm8s.h"

inline void gpio_input (volatile port_t * port, uint8_t pin) {
	uint8_t value = port->DDR;
	port->DDR = value & ~(1 << pin);
}

inline void gpio_output (volatile port_t * port, uint8_t pin) {
	uint8_t value = port->DDR;
	port->DDR = value | (1 << pin);
}

inline uint8_t gpio_read (uint8_t pin) {
	uint8_t value = PORT_D->ODR;
	return (value >> pin) & 0x1;
}

inline void gpio_write (uint8_t pin, uint8_t val) {
	uint8_t value = PORT_D->ODR;
	PORT_D->ODR = (value & ~(1 << pin)) | (1 << val);
}

//
//  Reset Timer 2 to a known state.
//
inline void init_timer2()
{
    TIM2_CR1_REG = 0;               // Turn everything TIM2 related off.
    TIM2_IER_REG = 0;
    TIM2_SR2 = 0;
    TIM2_CCER1 = 0;
    TIM2_CCER2 = 0;
    TIM2_CCER1 = 0;
    TIM2_CCER2 = 0;
    TIM2_CCMR1 = 0;
    TIM2_CCMR2 = 0;
    TIM2_CCMR3 = 0;
    TIM2_CNTRH = 0;
    TIM2_CNTRL = 0;
    TIM2_PSCR = 0;
    TIM2_ARRH  = 0;
    TIM2_ARRL  = 0;
    TIM2_CCR1H = 0;
    TIM2_CCR1L = 0;
    TIM2_CCR2H = 0;
    TIM2_CCR2L = 0;
    TIM2_CCR3H = 0;
    TIM2_CCR3L = 0;
    TIM2_SR1_REG = 0;
}


//
//  Setup Timer 2 to generate a 20 Hz interrupt based upon a 16 MHz timer.
//
inline void config_timer2()
{
    TIM2_PSCR = 0x01;       //  Prescaler = 8.
    TIM2_ARRH = (25000 >> 8);       //  High byte of 50,000.
    TIM2_ARRL = (25000 & 0xFF);       //  Low byte of 50,000.
    TIM2_IER->UIE = 1;       //  Enable the update interrupts.
    TIM2_CR1->CEN = 1;       //  Finally enable the timer.
}

inline uint16_t read_timer1 (void) {
	uint8_t h = TIM1_CNTRH;
	uint8_t l = TIM1_CNTRL;
	return((uint16_t)(h) << 8 | l);
}


inline void config_ports (void) {
	gpio_output(PORT_D, 0);
	gpio_output(PORT_D, 5);
	gpio_input(PORT_D, 6);
}

inline void uart1_2400 (void) {
    USART1_BRR1 = 0xA0;
    USART1_BRR2 = 0x1B;
}

inline void uart1_9600 (void) {
    USART1_BRR1 = 0x68;
    USART1_BRR2 = 0x03;
}

inline void uart1_19200 (void) {
    USART1_BRR1 = 0x34;
    USART1_BRR2 = 0x01;
}

inline void uart1_57600 (void) {
    USART1_BRR1 = 0x11;
    USART1_BRR2 = 0x06;
}

inline void uart1_115200 (void) {
    USART1_BRR1 = 0x08;
    USART1_BRR2 = 0x0B;
}

inline void uart1_230400 (void) {
    USART1_BRR1 = 0x04;
    USART1_BRR2 = 0x05;
}

inline void uart1_460800 (void) {
    USART1_BRR1 = 0x02;
    USART1_BRR2 = 0x03;
}

inline void uart1_921600 (void) {
    USART1_BRR1 = 0x01;
    USART1_BRR2 = 0x01;
}

inline void config_uart (void) {
    assign_reg(UART1_CR2, { .TIEN = 1, .TEN = 1, .RIEN = 1, .REN = 1 });
    assign_reg(UART1_CR3, { .STOP = UART1_CR2_STOP_TWO });
    uart1_19200();
}

inline uint8_t uart_tx_complete (void) {
	return USART1_SR & USART_SR_TXE;
}

uint8_t uart_rx_available (void) {
	return USART1_SR & USART_SR_RXNE;
}

inline void uart_wait () {
	// gpio_write(0, 1);
	while(!(USART1_SR & USART_SR_TXE));
	// gpio_write(0, 0);
}

inline void uart_write (char c) {
	USART1_DR = c;
}

inline void init_clock (void) {
    CLK_CKDIVR = 0x00; // Set the frequency to 16 MHz
    // CLK_PCKENR2 |= 0x02; // Enable clock to timer
    CLK_PCKENR1 = 0xFF; // Enable peripherals
}

#endif
