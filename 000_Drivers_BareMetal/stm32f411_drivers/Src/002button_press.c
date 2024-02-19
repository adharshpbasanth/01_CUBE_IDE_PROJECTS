/*
 * 002button_press.c
 *
 *  Created on: 29-Apr-2023
 *      Author: ad
 */


/*
 * 001led_toggle.c
 *
 *  Created on: 26-Apr-2023
 *      Author: ad
 */

#include "stm32f411xx.h"
#include "stm32f411xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000 ; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;		//button @PA0

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdcontrol = GPIO_NO_PUPD;

	GPIO_PeriClockcontrol(GPIOD,ENABLE);
	/*volatile uint32_t *register_address = (uint32_t*)0x40023830;  // Cast the address to a pointer to a volatile 32-bit integer

	// Set bit 3 to 1
	*register_address |= (1 << 3);*/
	GPIO_Init(&GpioLed);

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdcontrol = GPIO_NO_PUPD;

	GPIO_PeriClockcontrol(GPIOA,ENABLE);
	GPIO_Init(&GpioBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0)==1)
		{

			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
			delay();

		}
	}
	return 0;

}
