/*
 * stm32f411xx_gpio_driver.c
 *
 *  Created on: 23-Apr-2023
 *      Author: ad
 */

#include "stm32f411xx_gpio_driver.h"

//peripheral clock setup

/******************************************************************************************************************
 * @fn				- GPIO_PeriClockControl
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 ********************************************************************************************************************/

void GPIO_PeriClockcontrol(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else if(pGPIOx == GPIOA)
	{
		GPIOA_PCLK_DI();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_PCLK_DI();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_PCLK_DI();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_PCLK_DI();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_PCLK_DI();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_PCLK_DI();
	}

}

//Init and De- init

/******************************************************************************************************************
 * @fn				- GPIO_PeriClockControl
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 ********************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)		//GPIO_Handle_t is a structure and now *pGPIOHandle point towards it
{
	uint32_t temp=0; //temp.register

	//1. configure the mode of gpio pin

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)		//Check the pinmode value is less than 3. if greater than 3 it is interupt type. now we handling the non interupt type
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));	//temp = pin_number*2
		pGPIOHandle->pGPIOx->MODER &= ~( 0x03 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // clearing the bits before setting . 0x03 = 0b00000011 left shifted
		pGPIOHandle->pGPIOx->MODER |= temp; //setting the bits to register

	}
	else
	{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{ 	//1. Configure the FTSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->RTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1. configure the RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//1. configure both FTSR and RTSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		//2. Configure the GPIO Port selection in SYSCFG_EXTICR

		//3. Enable the exti interrupt delivery using IMR
		EXTI->IMR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}
	temp = 0;

	//2. configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x03 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp; //settings the bits to register
	temp = 0;

	//3. configure the pupd settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdcontrol << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x03 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp; //settings the bits to register
	temp = 0;

	//4. Configure the optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x01 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp; //settings the bits to register

	//5. confiqure the alt funtionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
	//Configure the alternate function register.
	uint8_t temp1, temp2;
	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8; //helps to select ALTFN[0] AND ALTFN[1]
	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;	//PIN_NUMBER %(mode) 8 - identifyies the pin number within the 32 bit register
	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2)); //clearing
	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2));
	}
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}

//Data read and write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber)& 0x00000001); //shifting the bit(pin) to bit zero AND 0x01
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR; //output the entire port
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//Write 1 to the output data register at the bit field corresponding to the pin
		pGPIOx ->ODR |= ( 1 << PinNumber);
	}
	else
	{
		//write 0
		pGPIOx ->ODR &= ~( 1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}

/*
 * IRQ Configuration and ISR handling
 *
 * ISERx: Interrupt Set-enable Registers
 * ICERx : Interrupt Clear-enable Registers
 */

void GPIO_IRQConfig(uint8_t IRQNumber,  uint8_t EnorDi) //removed uint8_t IRQPriority,
{
 if(EnorDi == ENABLE) 								//Set interrupt
 {
	 if(IRQNumber <= 31)
	 {
		 *NVIC_ISER0 |= ( 1 <<IRQNumber);
	 }
	 else if(IRQNumber > 31 && IRQNumber < 64)
	 {
		*NVIC_ISER1 |= ( 1 <<(IRQNumber %32));
	 }
	 else if(IRQNumber >= 64 && IRQNumber < 96)
	 {
		*NVIC_ISER2 |= ( 1 <<(IRQNumber %32));
	 }
 }
 else												//clear Interrupt
 {

	 if(IRQNumber <= 31)
	 {
		 *NVIC_ICER0 |= ( 1 <<IRQNumber);
	 }
	 else if(IRQNumber > 31 && IRQNumber < 64)
	 {
		*NVIC_ICER1 |= ( 1 <<(IRQNumber %32));
	 }
	 else if(IRQNumber >= 64 && IRQNumber < 96)
	 {
		*NVIC_ICER2 |= ( 1 <<(IRQNumber %32));
	 }
 }
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	//1. Interrupt Priority Register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;

	uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + (iprx)) |= (IRQPriority << shift_amount);
}

void GPIO_IRQHandling(int8_t PinNumber)
{
/*clear the EXTI PR Register corresponding to the pin number
 * When an interrupt occurs, the corresponding bit in the PR register is set to indicate that the interrupt is pending.
 */
	if(EXTI->PR & (1 << PinNumber))		//check both are same or not
	{
		//clear
		EXTI->PR |= (1 << PinNumber);
	}

}
