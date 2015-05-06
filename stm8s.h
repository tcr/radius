#ifndef __STM8S_H__
#define __STM8S_H__

#define IO_PTR(x)	((volatile uint8_t *)(x))
#define IO_TYPE(T, x)	((volatile T *)(x))

#define MAP_IO      ((volatile uint8_t *)0x5000)

typedef struct {
	uint8_t ODR;
	uint8_t IDR;
	uint8_t DDR;
	uint8_t CR1;
	uint8_t CR2;
} port_t;

#define PORT_A      ((volatile port_t *) (0x5000 + 0*0x5))
#define PORT_B      ((volatile port_t *) (0x5000 + 1*0x5))
#define PORT_C      ((volatile port_t *) (0x5000 + 2*0x5))
#define PORT_D      ((volatile port_t *) (0x5000 + 3*0x5))
#define PORT_E      ((volatile port_t *) (0x5000 + 4*0x5))

#define CLK_CKDIVR	(*IO_PTR(0x50c6))
#define CLK_PCKENR1	(*IO_PTR(0x50c7))
#define CLK_PCKENR2	(*IO_PTR(0x50ca))

#define USART1_SR	(*IO_PTR(0x5230))
#define USART1_DR	(*IO_PTR(0x5231))
#define USART1_BRR1	(*IO_PTR(0x5232))
#define USART1_BRR2	(*IO_PTR(0x5233))

typedef struct {
	uint8_t SBK:1;
	uint8_t RWU:1;
	uint8_t REN:1;
	uint8_t TEN:1;
	uint8_t ILIEN:1;
	uint8_t RIEN:1;
	uint8_t TCIEN:1;
	uint8_t TIEN:1;
} UART1_CR2_t;
#define UART1_CR2	IO_TYPE(UART1_CR2_t, 0x5235)
#define UART1_CR2_REG	(*IO_PTR(0x5235))

typedef struct {
	uint8_t LINEN:1;
	uint8_t STOP:2;
	uint8_t CLKEN:1;
	uint8_t CPOL:1;
	uint8_t CPHA:1;
	uint8_t LBCL:1;
} UART1_CR3_t;
#define UART1_CR3	IO_TYPE(UART1_CR2_t, 0x5236)
#define UART1_CR3_REG	(*IO_PTR(0x5236))

#define UART1_CR2_STOP_ONE 0
#define UART1_CR2_STOP_TWO 2
#define UART1_CR2_STOP_ONE_AND_HALF 3

#define TIM1_CR1	(*IO_PTR(0x5250))
#define TIM1_CNTRH	(*IO_PTR(0x525e))
#define TIM1_CNTRL	(*IO_PTR(0x525f))
#define TIM1_PSCRH	(*IO_PTR(0x5260))
#define TIM1_PSCRL	(*IO_PTR(0x5261))


typedef struct {
	uint8_t CEN:1;
	uint8_t UDIS:1;
	uint8_t URS:1;
	uint8_t OPM:1;
	uint8_t RESERVED0:3;
	uint8_t ARPE:1;
} tim2_cr1_t;

#define TIM2_CR1	IO_TYPE(tim2_cr1_t, 0x5300)
#define TIM2_CR1_REG	(*IO_PTR(0x5300))

typedef struct {
	uint8_t UIE:1;
	uint8_t CC1IE:1;
	uint8_t CC2IE:1;
	uint8_t CC3IE:1;
} tim2_ier_t;

#define TIM2_IER	IO_TYPE(tim2_ier_t, 0x5303)
#define TIM2_IER_REG	(*IO_PTR(0x5303))

typedef struct {
	uint8_t UIF:1;
	uint8_t CC1IF:1;
	uint8_t CC2IF:1;
	uint8_t CC3IF:1;
} tim2_sr1_t;

#define TIM2_SR1	IO_TYPE(tim2_sr1_t, 0x5304)
#define TIM2_SR1_REG	(*IO_PTR(0x5304))
#define TIM2_SR2	(*IO_PTR(0x5305))
#define TIM2_EGR	(*IO_PTR(0x5306))
#define TIM2_CCMR1	(*IO_PTR(0x5307))
#define TIM2_CCMR2	(*IO_PTR(0x5308))
#define TIM2_CCMR3	(*IO_PTR(0x5309))
#define TIM2_CCER1	(*IO_PTR(0x530A))
#define TIM2_CCER2	(*IO_PTR(0x530B))
#define TIM2_CNTRH	(*IO_PTR(0x530C))
#define TIM2_CNTRL	(*IO_PTR(0x530D))
#define TIM2_PSCR	(*IO_PTR(0x530E))
#define TIM2_ARRH	(*IO_PTR(0x530F))
#define TIM2_ARRL	(*IO_PTR(0x5310))
#define TIM2_CCR1H	(*IO_PTR(0x5311))
#define TIM2_CCR1L	(*IO_PTR(0x5312))
#define TIM2_CCR2H	(*IO_PTR(0x5313))
#define TIM2_CCR2L	(*IO_PTR(0x5314))
#define TIM2_CCR3H	(*IO_PTR(0x5315))
#define TIM2_CCR3L	(*IO_PTR(0x5316))

#define USART_CR2_TEN (1 << 3)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)
#define USART_SR_RXNE (1 << 5)

#define SPI_BLOCK   (*(volatile uint8_t *)0x5200)
#define SPI_SR      (*((&SPI_BLOCK) + 0x3))

typedef enum {
	IRQ_TLI = 0,
	IRQ_AWU,
	IRQ_CLK,
	IRQ_EXTI0,
	IRQ_EXTI1,
	IRQ_EXTI2,
	IRQ_EXTI3,
	IRQ_EXTI4,
	IRQ_RESERVED0,
	IRQ_RESERVED1,
	IRQ_SPI,
	IRQ_TIM1,
	IRQ_TIM1_COMPARE,
	IRQ_TIM2,
	IRQ_TIM2_COMPARE,
	IRQ_RESERVED2,
	IRQ_RESERVED3,
	IRQ_UART1,
	IRQ_UART1_FULL,
	IRQ_I2C,
	IRQ_RESERVED4,
	IRQ_RESERVED5,
	IRQ_ADC1,
	IRQ_TIM4,
	IRQ_FLASH = 24
} irq_t;

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

inline void __nop(void) {
	__asm
	nop
	__endasm;
}

#define assign_reg(X, ...) do { \
    static const X ## _t stru = __VA_ARGS__; \
    X ## _REG = *((volatile uint8_t *) &stru); \
} while (0)

#endif
