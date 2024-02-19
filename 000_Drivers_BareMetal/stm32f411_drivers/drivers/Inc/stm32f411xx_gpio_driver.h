/*
 * stm32f411xx_gpio_driver.h
 *
 *  Created on: 23-Apr-2023
 *      Author: ad
 *
 *      ----BOARD SPECIFIC------
 */

#ifndef INC_STM32F411XX_GPIO_DRIVER_H_
#define INC_STM32F411XX_GPIO_DRIVER_H_

#include "stm32f411xx.h"

/**************************************************************************************************************************************
 * This is a Configuration Structure for a GPIO pin
 *******************************************************************************************************************************************/

typedef struct
{
	uint8_t GPIO_PinNumber;				//GPIO Pin number
	uint8_t GPIO_PinMode;				//GPIO mode
	uint8_t GPIO_PinSpeed;				//GPIO Speed
	uint8_t GPIO_PinPuPdcontrol;		//GPIO pullup-pulldown  - for input
	uint8_t GPIO_PinOPType;				//GPIO output type		- for output
	uint8_t GPIO_PinAltFunMode;			//GPIO Alternate function mode
}GPIO_PinConfig_t;

/**************************************************************************************************************************************
 * This is a Handle Structure for a GPIO pin
 *******************************************************************************************************************************************/

typedef struct
{
	GPIO_RegDef_t *pGPIOx;				//This holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;	//This holds GPIO pin configuration settings
}GPIO_Handle_t;

//GPIO_PIN_NUMBERS (total 16 I/O pins are there in each 32 bit port

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

//GPIO possible modes <gpio port mode register>

#define GPIO_MODE_IN		0	//Input (reset state)
#define GPIO_MODE_OUT		1	//General purpose output mode
#define GPIO_MODE_ALTFN		2	//Alternate function mode
#define GPIO_MODE_ANALOG	3	//Analog mode
/***************here interupt mode and non interupt mode is seting*********************/
#define GPIO_MODE_IT_FT		4 	
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

//GPIO PIN POSSIBLE OUTPUT TYPES

#define GPIO_OP_TYPE_PP		0	//Output push-pull
#define GPIO_OP_TYPE_OD		1	//Output open-drain

//GPIO_PIN_SPEED

#define GPIO_SPEED_LOW		0	//low speed
#define GPIO_SPEED_MEDIUM	1	//Medium speed
#define GPIO_SPEED_FAST		2	//Fast speed
#define GPIO_SPEED_HIGH		3	//High speed

//GPIO PORT PULL-UP/PULL-DOWN REGISTER (GPIO_PUPDR)
#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_pIN_PD			2


/**************************************************************************************************************************************
 * APIs supported by this driver
 * for more information about the APIs check the function definitions
 *******************************************************************************************************************************************/
//peripheral clock setup
void GPIO_PeriClockcontrol(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);  //prototyping

//Init and De- init
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

//Data read and write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

//IRQ Configuration and ISR handling
void GPIO_IRQConfig(uint8_t IRQNumber,  uint8_t EnorDi); //note : uint8_t IRQPriority, removed
void GPIO_IRQHandling(int8_t PinNumber);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);











#endif /* INC_STM32F411XX_GPIO_DRIVER_H_ */
