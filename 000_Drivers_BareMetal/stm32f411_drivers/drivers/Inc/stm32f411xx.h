/*
 * stm32f411xx.h
 *
 *  Created on: Apr 18, 2023
 *      Author: ad
 */
/*NOTE : 1. user upercase for macro names
 	 	 2. use prefix ( HAL_... ) helps to identify this macro is from which layer
 	 	 3. In this project, it is suggested to use DRV_XXXX - this avoid using the same name some other file*/


/*-----------------MCU SPECIFIC HEADER FIEL---------------------------------------------*/

#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#include <stdint.h>

/******************************************************************************************************************
 -----------------------START: Processor Specific Details-------------------------------------------------------
 ***********************************************************************************************************************/

/*
 * ARM CORTEX M4 Processor NVIC ISERx Register Address
 * Interrupt Set-Enable Register
 */
#define NVIC_ISER0		( (volatile uint32_t*)0xE000E100 )
#define NVIC_ISER1		( (volatile uint32_t*)0xE000E104 )
#define NVIC_ISER2		( (volatile uint32_t*)0xE000E108 )
#define NVIC_ISER3		( (volatile uint32_t*)0xE000E10C )

/*
 * ARM CORTEX M4 Processor NVIC ICERx Register Address
 * Interrupt Clear-Enable Register
 */
#define NVIC_ICER0		( (volatile uint32_t*)0xE000E180 )
#define NVIC_ICER1		( (volatile uint32_t*)0xE000E184 )
#define NVIC_ICER2		( (volatile uint32_t*)0xE000E188 )
#define NVIC_ICER3		( (volatile uint32_t*)0xE000E18C )

/*
* ARM CORTEX MX Processor Priority Register Address Calculation
*/
#define NVIC_PR_BASE_ADDR 			(( volatile uint32_t*)0xE000E400)
/*
* ARM CORTEX MX Processor Number of priority bits implemented in Priority Register
*/
#define NO_PR_BITS_IMPLEMENTED		4		

/******************************************************************************************************************
 -----------------------BASE ADDRESS OF FLASH AND SRAM MEMORIES--------------------------------------------
 ***********************************************************************************************************************/
#define FLASH_BASEADDR 	0x08000000U  //address should always keep as unsigned. use ul - unsinged long
#define SRAM1_BASEADDR 	0x20000000U  //get this information easily from microcontroller specifications document
//#define SRAM2_BASEADDR
#define ROM 			0x1FFF0000U //system memory is called ROM
#define SRAM 			SRAM1_BASEADDR

/******************************************************************************************************************
 -----------------------AHBx AND APBx BUS PERIPHERAL BASE ADDRESSES--------------------------------------------
 ***********************************************************************************************************************/
#define PERIPH_BASEADDR		0x40000000U  		//Peripheral base address
#define APB1PERIPH_BASEADDR	PERIPH_BASEADDR  	//APB1
#define APB2PERIPH_BASEADDR	0x40010000U  		//APB2
#define AHB1PERIPH_BASEADDR	0x40020000U  		//AHB1
#define AHB2PERIPH_BASEADDR	0x50000000U  		//AHB2

/******************************************************************************************************************
 -----------------------BASE ADDRESS OF PERIPHERALS WHICH ARE HANGING ON AHB1 BUS--------------------------------------------
 ***********************************************************************************************************************/
#define GPIOA_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0000)  //GPIOA
#define GPIOB_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0400)  //GPIOB
#define GPIOC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0800)  //GPIOC
#define GPIOD_BASEADDR	(AHB1PERIPH_BASEADDR + 0x0C00)  //GPIOD
#define GPIOE_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1000)  //GPIOE
#define GPIOH_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1C00)  //GPIOH

#define RCC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x3800)	//RCC
#define EXTI_BASEADDR	(APB2PERIPH_BASEADDR + 0x3C00)  //EXTI

/******************************************************************************************************************
 -----------------------BASE ADDRESS OF PERIPHERALS WHICH ARE HANGING ON APB1 BUS--------------------------------------------
 ***********************************************************************************************************************/
#define I2C1_BASEADDR (APB1PERIPH_BASEADDR	 + 0x5400)  	//I2C1
#define I2C2_BASEADDR (APB1PERIPH_BASEADDR	 + 0x5800)  	//I2C2
#define I2C3_BASEADDR (APB1PERIPH_BASEADDR	 + 0x5C00)  	//I2C3

#define SPI2_BASEADDR (APB1PERIPH_BASEADDR	 + 0x3800)  	//SPI2
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR	 + 0x3C00)	//SPI3

#define USART2_BASEADDR (APB1PERIPH_BASEADDR	 + 0x4400)  //USART2

/******************************************************************************************************************
 -----------------------BASE ADDRESS OF PERIPHERALS WHICH ARE HANGING ON APB2 BUS--------------------------------------------
 ***********************************************************************************************************************/
#define USART1_BASEADDR (AHB2PERIPH_BASEADDR + 0x1000)	//USART1
#define USART6_BASEADDR (AHB2PERIPH_BASEADDR + 0x1400)	//USART6

#define SPI1_BASEADDR (AHB2PERIPH_BASEADDR + 0x3000)	//SPI1
#define SPI4_BASEADDR (AHB2PERIPH_BASEADDR + 0x3400)	//SPI4
#define SPI5_BASEADDR (AHB2PERIPH_BASEADDR + 0x5000)	//SPI5


/******************************************************************************************************************
 -----------------------PERIPHERAL REGISTER DEFINITION STRUCTURES--------------------------------------------
 ***********************************************************************************************************************/

typedef struct			//Every address incremented by 32bit - (uint32_t)
{
	volatile uint32_t MODER;	//offset = 0x00; use volatile - GPIO is highly volatile
	volatile uint32_t OTYPER;	//offset = 0x04
	volatile uint32_t OSPEEDR;	//offset = 0x08
	volatile uint32_t PUPDR;	//offset = 0x0C
	volatile uint32_t IDR;		//offset = 0x10
	volatile uint32_t ODR;		//offset = 0x14
	volatile uint32_t BSRR;		//offset = 0x18
	volatile uint32_t LCKR;		//offset = 0x1C
	volatile uint32_t AFR[2];	//offset = 0x20; AFR[1] = AFRL & AFR[2] = AFRH

}GPIO_RegDef_t; //GPIOx_REGISTERS

typedef struct
{
	volatile uint32_t CR;			//offset = 0x00;
	volatile uint32_t PLLCFGR;		//offset = 0x04;
	volatile uint32_t CFGR;			//offset = 0x08;
	volatile uint32_t CIR;			//offset = 0x0C;
	volatile uint32_t AHB1RSTR;		//offset = 0x10;
	volatile uint32_t AHB2RSTR;		//offset = 0x14;
	uint32_t RESERVED1[2];			//offset = 0x18;
	volatile uint32_t APB1RSTR;		//offset = 0x20;
	volatile uint32_t APB2RSTR;		//offset = 0x24;
	uint32_t RESERVED2[2];			//offset = 0x28;
	volatile uint32_t AHB1ENR;		//offset = 0x30;
	volatile uint32_t AHB2ENR;		//offset = 0x34;
	uint32_t RESERVED3[2];			//offset = 0x38;
	volatile uint32_t APB1ENR;		//offset = 0x40;
	volatile uint32_t APB2ENR;		//offset = 0x44;
	uint32_t RESERVED4[2];			//offset = 0x48;
	volatile uint32_t AHB1LPENR;	//offset = 0x50;
	volatile uint32_t AHB2LPENR;	//offset = 0x54;
	uint32_t RESERVED5[2];			//offset = 0x58;
	volatile uint32_t APB1LPENR;	//offset = 0x60;
	volatile uint32_t APB2LPENR;	//offset = 0x64;
	uint32_t RESERVED6[2];			//offset = 0x68;
	volatile uint32_t BDCR;			//offset = 0x70;
	volatile uint32_t CSR;			//offset = 0x74;
	volatile uint32_t RESERVED7[2];	//offset = 0x78;
	volatile uint32_t SSCGR;		//offset = 0x80;
	volatile uint32_t PLLI2SCFGR;	//offset = 0x84;
	uint32_t RESERVED8;				//offset = 0x88;
	volatile uint32_t DCKCFGR;		//offset = 0x8C;
}RCC_RegDef_t; //RCC_REGISTER

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	volatile uint32_t IMR;		/*0x00 Interrupt mask on line x -
										0: Interrupt request from line x is masked
										1: Interrupt request from line x is not masked*/
	volatile uint32_t EMR;		//0x04 Event mask register (EXTI_EMR)
	volatile uint32_t RTSR;	//0x08 Rising trigger selection register (EXTI_RTSR)
	volatile uint32_t FTSR;	//0x0C Falling trigger selection register (EXTI_FTSR)
	volatile uint32_t SWIER;	//0x10 Software interrupt event register (EXTI_SWIER)
	volatile uint32_t PR;		//0x14 Pending register (EXTI_PR)
}EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	volatile uint32_t MEMRMP; 		/* 0x00 SYSCFG memory remap register (SYSCFG_MEMRMP)
									00: Main Flash memory mapped at 0x0000 0000
									01: System Flash memory mapped at 0x0000 0000
									11: Embedded SRAM mapped at 0x0000 0000*/
	volatile uint32_t PMC;			// 0x04 peripheral mode configuration register
	volatile uint32_t EXTICR[4];	//0x08 - 0x14external interrupt configuration register
	uint32_t RESERVED1[2];			//0x18 - 0x1C
	volatile uint32_t CMPCR; 		//0x20 Compensation cell control register
}SYSCFG_RegDef_t;


/*
 * register definition structure for SPI and I2C
 */
typedef struct
{
	volatile uint32_t SPI_CR1;		//0x00	offset
	volatile uint32_t SPI_CR2;		//0x04
	volatile uint32_t SPI_SR;		//0x08
	volatile uint32_t SPI_DR;		//0x0C
	volatile uint32_t SPI_CRCPR;	//0x10
	volatile uint32_t SPI_RXCRCR;	//0x14
	volatile uint32_t SPI_TXCRCR;	//0x18
	volatile uint32_t SPI_I2CFGR;	//0x1C
	volatile uint32_t SPI_I2SPR;	//0x20
}SPI_RegDef_t;

/******************************************************************************************************************
 -----------------------PERIPHERAL DEFINITION : Defining the peripherals base to register definition----------
 ***********************************************************************************************************************/
#define GPIOA 	((GPIO_RegDef_t*)GPIOA_BASEADDR) //This type cast the GPIOA_BASEADDR as structure (GPIO_RegDef_t)
#define GPIOB 	((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 	((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 	((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 	((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH 	((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC 	((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI 	((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG 	((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1 	((SPI_RegDef_t*)SPI1_BASEADDR)	//structure points to the base address of SPI1
#define SPI2	((SPI_RegDef_t*)SPI2_BASEADDR)	//structure points to the base address of SPI2
#define SPI3	((SPI_RegDef_t*)SPI3_BASEADDR)	//structure points to the base address of SPI3
#define SPI4	((SPI_RegDef_t*)SPI4_BASEADDR)	//structure points to the base address of SPI4
#define SPI5	((SPI_RegDef_t*)SPI5_BASEADDR)	//structure points to the base address of SPI5

/******************************************************************************************************************
 -----------------------CLOCK ENABLE/DISABLE MACROS FOR GPIOx----------
 ***********************************************************************************************************************/
#define GPIOA_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 0))
#define GPIOB_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 1))
#define GPIOC_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 2))
#define GPIOD_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 3))
#define GPIOE_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 4))
#define GPIOH_PCLK_EN()		( RCC ->AHB1ENR |= ( 1 << 7))

#define GPIOA_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 0))
#define GPIOB_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 1))
#define GPIOC_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 2))
#define GPIOD_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 3))
#define GPIOE_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 4))
#define GPIOH_PCLK_DI()		( RCC ->AHB1ENR &= ~( 1 << 7))
/******************************************************************************************************************
 -----------------------CLOCK ENABLE/DISABLE MACROS FOR I2Cx----------
 ***********************************************************************************************************************/
#define I2C1_PCLK_EN()		( RCC ->APB1ENR |= ( 1 << 21))
#define I2C2_PCLK_EN()		( RCC ->APB1ENR |= ( 1 << 22))
#define I2C3_PCLK_EN()		( RCC ->APB1ENR |= ( 1 << 23))

#define I2C1_PCLK_DI()		( RCC ->APB1ENR &= ~( 1 << 21))
#define I2C2_PCLK_DI()		( RCC ->APB1ENR &= ~( 1 << 22))
#define I2C3_PCLK_DI()		( RCC ->APB1ENR &= ~( 1 << 23))
/******************************************************************************************************************
 -----------------------CLOCK ENABLE/DISABLE MACROS FOR SPIx----------
 ***********************************************************************************************************************/
#define SPI1_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 12))
#define SPI2_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 14))
#define SPI3_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 15))
#define SPI4_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 13))
#define SPI5_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 20))

#define SPI1_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 12))
#define SPI2_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 14))
#define SPI3_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 15))
#define SPI4_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 13))
#define SPI5_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 20))
/******************************************************************************************************************
 -----------------------CLOCK ENABLE/DISABLE MACROS FOR USARTx----------
 ***********************************************************************************************************************/
#define USART1_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 4))
#define USART2_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 5))
#define USART6_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 5))

#define USART1_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 4))
#define USART2_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 5))
#define USART6_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 5))
/******************************************************************************************************************
 -----------------------CLOCK ENABLE/DISABLE MACROS FOR SYSCFG----------
 ***********************************************************************************************************************/
#define SYSCFG_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 14))

#define SYSCFG_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 14))

/******************************************************************************************************************
-----RESET GPIO REGISTER (separate register to reset GPIOx is present is RCC (AHB1RSTR)------
 ***********************************************************************************************************************/
#define GPIOA_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 0)); (RCC -> AHB1RSTR &= ~(1<<0)); } while(0) //set and reset the bit in single macro using do while(0)
#define GPIOB_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 1)); (RCC -> AHB1RSTR &= ~(1<<1)); } while(0)
#define GPIOC_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 2)); (RCC -> AHB1RSTR &= ~(1<<2)); } while(0)
#define GPIOD_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 3)); (RCC -> AHB1RSTR &= ~(1<<3)); } while(0)
#define GPIOE_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 4)); (RCC -> AHB1RSTR &= ~(1<<4)); } while(0)
#define GPIOH_REG_RESET()		do {( RCC -> AHB1RSTR |= (1 << 7)); (RCC -> AHB1RSTR &= ~(1<<7)); } while(0)

/******************************************************************************************************************
 -----------------------Some generic macros---------
 ***********************************************************************************************************************/
#define ENABLE 			1
#define DISABLE 		0
#define SET				ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET	SET
#define	GPIO_PIN_RESET	RESET


#define IRQ_NO_EXTI0	6
#define IRQ_NO_EXTI1	7
#define IRQ_NO_EXTI2	8
#define IRQ_NO_EXTI3	9
#define IRQ_NO_EXTI4	10


#endif /* INC_STM32F411XX_H_ */
