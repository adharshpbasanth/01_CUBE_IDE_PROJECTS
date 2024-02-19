/*
 * 003button_interrupt.c
 *
 *  Created on: 17-May-2023
 *      Author: adhar
 */

#include "stm32f411xx.h"
#include "stm32f411xx_gpio_driver.h"
#include <string.h>

void delay(void)		//provides a delay
{
	for(uint32_t i = 0; i < 500000 ; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;									//button @PA0
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GpioBtn,0,sizeof(GpioLed));

	GpioLed.pGPIOx = GPIOD;											//led configuration
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;			//pin no. 12
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;			//output type
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;			//speed = fast
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;		//output type = push pull
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdcontrol = GPIO_NO_PUPD;	//input type no need to configure as per my understanding.

	GPIO_PeriClockcontrol(GPIOD,ENABLE);							//enable the peripheral clock for GPIO PORT D
	GPIO_Init(&GpioLed);											//Configuration got initialized here.

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RT;				//here mode should be selected for FTSR OR RTSR - falling edge external interrupt trigger and rising edge external interrupt trigger.
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdcontrol = GPIO_NO_PUPD;

	GPIO_PeriClockcontrol(GPIOA,ENABLE);
	GPIO_Init(&GpioBtn);

	//IRQ CONFIGURATION
	GPIO_IRQConfig(IRQ_NO_EXTI0,ENABLE);
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,15);	//This is optional

	/*while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0)==1)
		{

			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
			delay();

		}
	}*/
	while(1);
	return 0;

}
//Implementation of ISR
void EXTI0_IRQHandler(void)
{
	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_0);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);

}
