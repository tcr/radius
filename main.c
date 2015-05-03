#include <stdio.h>
#include <stdint.h>

#include "stm8s.h"

inline void gpio_input (uint8_t pin) {
	uint8_t value = PD_DDR;
	PD_DDR = value & ~(1 << pin);
}

inline void gpio_output (uint8_t pin) {
	uint8_t value = PD_DDR;
	PD_DDR = value | (1 << pin);
}

inline void gpio_write (uint8_t pin, uint8_t val) {
	uint8_t value = PD_ODR;
	PD_ODR = (value & ~(1 << pin)) | (1 << val);
}

void main (void)
{
	uint32_t i;

	gpio_output(0);

	while (1) {
		gpio_write(0, 0);
		for (i = 0; i < 1e4; i++) {
			__asm
			nop
			__endasm;
		}
		gpio_write(0, 1);
		for (i = 0; i < 1e4; i++) {
			__asm
			nop
			__endasm;
		}
	}
}
