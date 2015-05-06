#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "stm8s.h"
#include "lib.h"

void irq_timer2 (void) __interrupt(IRQ_TIM2) {
	// gpio_write(0, gpio_read(0));
	//  Reset the interrupt otherwise it will fire again straight away.
	TIM2_SR1->UIF = 0;
}


const char* uartstr = "Tessel Tag\r\n";
const uint8_t uartstr_len = 12;
uint8_t pos = 0;

void uart_timer (void) __interrupt(IRQ_UART1) {
    volatile uint8_t a;
    // if (uart_tx_complete()) {
    //     uart_write(uartstr[pos]);
    //     if (++pos >= uartstr_len) {
    //         pos = 0;
    //     }
    // }
    if (uart_rx_available()) {
        gpio_write(0, 1);
        a = USART1_DR;
        uart_write(a);
    }
}

//
//  Main program loop.
//
void main (void) {
    volatile uint8_t a;
    __disable_interrupt();
    init_clock();
    init_timer2();
    config_ports();
    config_timer2();
    config_uart();
    gpio_write(0, 0);

    a = USART1_DR;
    __enable_interrupt();

    // 
    // uart_write('A');
    while (1) {
        __wait_for_interrupt();
        // if (uart_rx_available()) {
        //     volatile uint8_t a = USART1_DR;
            // gpio_write(0, 1);
        // }
    }
}
