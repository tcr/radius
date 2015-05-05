#include <stdio.h>
#include <stdint.h>

#include "stm8s.h"

inline void gpio_input (uint8_t pin) {
	uint8_t value = PORT_D->DDR;
	PORT_D->DDR = value & ~(1 << pin);
}

inline void gpio_output (uint8_t pin) {
	uint8_t value = PORT_D->DDR;
	PORT_D->DDR = value | (1 << pin);
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
//  Timer 2 Overflow handler.
//
void irq_timer2(void) __interrupt(IRQ_TIM2)
{
	gpio_write(0, gpio_read(0));
	//  Reset the interrupt otherwise it will fire again straight away.
	TIM2_SR1->UIF = 0;
}

//
//  Reset Timer 2 to a known state.
//
void InitialiseTimer2()
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
void SetupTimer2()
{
    TIM2_PSCR = 0x03;       //  Prescaler = 8.
    TIM2_ARRH = (25000 >> 8);       //  High byte of 50,000.
    TIM2_ARRL = (25000 & 0xFF);       //  Low byte of 50,000.
    TIM2_IER->UIE = 1;       //  Enable the update interrupts.
    TIM2_CR1->CEN = 1;       //  Finally enable the timer.
}


void SetupOutputPorts()
{
	gpio_output(0);

}


inline void __disable_interrupt(void) {
	__asm
	sim
	__endasm;
}

inline void __enable_interrupt(void) {
	__asm
	rim
	__endasm;
}

inline void __wait_for_interrupt(void) {
	__asm
	wfi
	__endasm;
}

//
//  Main program loop.
//
void main (void)
{
    __disable_interrupt();
    SetupOutputPorts();
    InitialiseTimer2();
    SetupTimer2();
    __enable_interrupt();
    while (1)
    {
        __wait_for_interrupt();
    }
}


// void main (void)
// {
// 	uint32_t i;

// 	gpio_output(0);

// 	while (1) {
// 		gpio_write(0, 0);
// 		for (i = 0; i < 1e4; i++) {
// 			__asm
// 			nop
// 			__endasm;
// 		}
// 		gpio_write(0, 1);
// 		for (i = 0; i < 1e4; i++) {
// 			__asm
// 			nop
// 			__endasm;
// 		}
// 	}
// }
