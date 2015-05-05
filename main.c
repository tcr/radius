#include <stdio.h>
#include <stdint.h>

#include "stm8s.h"

inline void gpio_input (uint8_t pin) {
	uint8_t value = PORT_D->DDR;
	PORT_D->DDR = value & ~(1 << pin);
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
void init_timer2()
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
void config_timer2()
{
    TIM2_PSCR = 0x03;       //  Prescaler = 8.
    TIM2_ARRH = (25000 >> 8);       //  High byte of 50,000.
    TIM2_ARRL = (25000 & 0xFF);       //  Low byte of 50,000.
    TIM2_IER->UIE = 1;       //  Enable the update interrupts.
    TIM2_CR1->CEN = 1;       //  Finally enable the timer.
}


void config_ports (void) {
	gpio_output(PORT_D, 0);
	gpio_output(PORT_D, 5);
	gpio_output(PORT_D, 6);
}

inline void config_uart (void) {
	USART1_CR2 = USART_CR2_TEN; // Allow TX & RX
	USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	USART1_BRR2 = 0x03;
	USART1_BRR1 = 0x68; // 9600 baud
}


inline void uart_wait () {
	// gpio_write(0, 1);
	while(!(USART1_SR & USART_SR_TXE));
	// gpio_write(0, 0);
}

inline void uart_write (char c) {
	uart_wait();
	USART1_DR = c;
}

//
//  Timer 2 Overflow handler.
//
void irq_timer2 (void) __interrupt(IRQ_TIM2) {
	gpio_write(0, gpio_read(0));
	//  Reset the interrupt otherwise it will fire again straight away.
	TIM2_SR1->UIF = 0;

    uart_write('T');
    uart_write('a');
    uart_write('g');
    uart_write('\r');
    uart_write('\n');
}

uint16_t clock (void) {
	uint8_t h = TIM1_CNTRH;
	uint8_t l = TIM1_CNTRL;
	return((uint16_t)(h) << 8 | l);
}

//
//  Main program loop.
//
void main (void) {
    __disable_interrupt();
	CLK_CKDIVR = 0x00; // Set the frequency to 16 MHz
	// CLK_PCKENR2 |= 0x02; // Enable clock to timer
	CLK_PCKENR1 = 0xFF; // Enable peripherals

    init_timer2();
    config_ports();
    config_timer2();
    config_uart();
    __enable_interrupt();

    while (1) {
        __wait_for_interrupt();
    }
}
