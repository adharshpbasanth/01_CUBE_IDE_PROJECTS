/*
 * main.c
 *
 *  Created on: 17-May-2023
 *      Author: adhar
 */

#include "stm32f411xx.h"

int main(void)
{
	return 0;
}

void EXTI0_IRQHandler(void)
{
	//handle the interrupt
	GPIO_IRQHandling(0);
}
