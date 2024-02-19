/*
 * stm32f411xx_spi_drivers.c
 *
 *  Created on: 24-May-2023
 *      Author: adhar
 */

#include "stm32f411xx_spi_driver.h"

//peripheral clock setup
void SPI_PeriClockcontrol(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if(pSPIx == SPI4)
		{
			SPI4_PCLK_EN();
		}
		else if(pSPIx == SPI5)
		{
			SPI5_PCLK_EN();
		}
	}
	else if(pSPIx == SPI1)
	{
		SPI1_PCLK_DI();
	}
	else if(pSPIx == SPI2)
	{
		SPI2_PCLK_DI();
	}
	else if(pSPIx == SPI3)
	{
		SPI3_PCLK_DI();
	}
	else if(pSPIx == SPI4)
	{
		SPI4_PCLK_DI();
	}
	else if(pSPIx == SPI5)
	{
		SPI5_PCLK_DI();
	}

}

//Init and De- init
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len);
void SPI_RecievData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */
void SPI_IRQConfig(uint8_t IRQNumber,  uint8_t EnorDi); //note : uint8_t IRQPriority, removed
void SPI_IRQHandling(SPI_Handle_t *pHandle);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

