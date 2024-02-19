/*
 * stm32f411xx_spi_drivers.h
 *
 *  Created on: 23-May-2023
 *      Author: adhar
 */

#ifndef INC_STM32F411XX_SPI_DRIVER_H_
#define INC_STM32F411XX_SPI_DRIVER_H_

#include "stm32f411xx.h"

/**************************************************************************************************************************************
 * Configuration Structure for SPI pin
 *******************************************************************************************************************************************/
typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/**************************************************************************************************************************************
 * Handle Structure for SPI pin
 *******************************************************************************************************************************************/
typedef struct
{
	SPI_RegDef_t *pSPIx;		//This hold the base address of SPIx
	SPI_Config_t SPIConfig;		//Point to the configuration Structure.
}SPI_Handle_t;


/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD				1		//Full duplex
#define SPI_BUS_CONFIG_HD				2		//Half duplex
#define SPI_BUS_CONFIG_SIMPLEX_TXONLY	3
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	4

/*
 * @SPI_SclkSpeed
 */



/**************************************************************************************************************************************
 * APIs supported by this driver
 * for more information about the APIs check the function definitions
 *******************************************************************************************************************************************/
//peripheral clock setup
void SPI_PeriClockcontrol(SPI_RegDef_t *pSPIx, uint8_t EnorDi);  //prototyping

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


#endif /* INC_STM32F411XX_SPI_DRIVER_H_ */
