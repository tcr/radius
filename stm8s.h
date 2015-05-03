#define MAP_IO      ((volatile uint8_t *)0x5000)

#define PA_ODR		(MAP_IO[(0*0x5)+0x0])
#define PA_IDR		(MAP_IO[(0*0x5)+0x1])
#define PA_DDR		(MAP_IO[(0*0x5)+0x2])
#define PA_CR1		(MAP_IO[(0*0x5)+0x3])
#define PA_CR2		(MAP_IO[(0*0x5)+0x4])

#define PB_ODR		(MAP_IO[(1*0x5)+0x0])
#define PB_IDR		(MAP_IO[(1*0x5)+0x1])
#define PB_DDR		(MAP_IO[(1*0x5)+0x2])
#define PB_CR1		(MAP_IO[(1*0x5)+0x3])
#define PB_CR2		(MAP_IO[(1*0x5)+0x4])

#define PC_ODR		(MAP_IO[(2*0x5)+0x0])
#define PC_IDR		(MAP_IO[(2*0x5)+0x1])
#define PC_DDR		(MAP_IO[(2*0x5)+0x2])
#define PC_CR1		(MAP_IO[(2*0x5)+0x3])
#define PC_CR2		(MAP_IO[(2*0x5)+0x4])

#define PD_ODR		(MAP_IO[(3*0x5)+0x0])
#define PD_IDR		(MAP_IO[(3*0x5)+0x1])
#define PD_DDR		(MAP_IO[(3*0x5)+0x2])
#define PD_CR1		(MAP_IO[(3*0x5)+0x3])
#define PD_CR2		(MAP_IO[(3*0x5)+0x4])

#define PE_ODR		(MAP_IO[(4*0x5)+0x0])
#define PE_IDR		(MAP_IO[(4*0x5)+0x1])
#define PE_DDR		(MAP_IO[(4*0x5)+0x2])
#define PE_CR1		(MAP_IO[(4*0x5)+0x3])
#define PE_CR2		(MAP_IO[(4*0x5)+0x4])

#define CLK_DIVR	(*(volatile uint8_t *)0x50c6)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c7)
#define CLK_PCKENR2	(*(volatile uint8_t *)0x50ca)

#define USART1_SR	(*(volatile uint8_t *)0x5230)
#define USART1_DR	(*(volatile uint8_t *)0x5231)
#define USART1_BRR1	(*(volatile uint8_t *)0x5232)
#define USART1_BRR2	(*(volatile uint8_t *)0x5233)
#define USART1_CR2	(*(volatile uint8_t *)0x5235)
#define USART1_CR3	(*(volatile uint8_t *)0x5236)

#define TIM1_CR1	(*(volatile uint8_t *)0x5250)
#define TIM1_CNTRH	(*(volatile uint8_t *)0x525e)
#define TIM1_CNTRL	(*(volatile uint8_t *)0x525f)
#define TIM1_PSCRH	(*(volatile uint8_t *)0x5260)
#define TIM1_PSCRL	(*(volatile uint8_t *)0x5261)

#define USART_CR2_TEN (1 << 3)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)

#define SPI_BLOCK   (*(volatile uint8_t *)0x5200)
#define SPI_SR      (*((&SPI_BLOCK) + 0x3))

#define IRQ_SPI     10
