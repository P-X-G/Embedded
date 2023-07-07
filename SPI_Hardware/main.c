#include "spi_hardware.h"


void Spi_Init(Spi_ConfigType* ConfigPtr){
	// Step 1: Initialize SPI
	RCC_APB2PeriphClockCmd(SPIx_RCC, ENABLE);
	ConfigPtr->SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
	ConfigPtr->SPI_CPHA = SPI_CPHA_1Edge;
	ConfigPtr->SPI_CPOL = SPI_CPOL_Low;
	ConfigPtr->SPI_DataSize = SPI_DataSize_8b;
	ConfigPtr->SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	ConfigPtr->SPI_FirstBit = SPI_FirstBit_MSB;
	ConfigPtr->SPI_Mode = SPI_Mode_Master;
	ConfigPtr->SPI_NSS = SPI_NSS_Soft | SPI_NSSInternalSoft_Set;
	SPI_Init(SPIx, ConfigPtr); 
	SPI_Cmd(SPIx, ENABLE);
}

Std_ReturnType Spi_DeInit(void){
	if(SPIx == SPI1){
		DISABLE_SPIx;
		return E_OK;
	}
	else if(SPIx == SPI2){
		DISABLE_SPIx;
		return E_OK;
	}
	else if(SPIx == SPI3){
		DISABLE_SPIx;
		return E_OK;
	}else{
		return E_NOT_OK;
	}
}

Std_ReturnType Spi_WriteIB (Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPtr){
	switch(Channel){
		case 1:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPtr == 0){
				return E_NOT_OK;
			}
			while(DataBufferPtr != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);		
				/* Send SPIx data */
				SPI_I2S_SendData(SPIx, *DataBufferPtr++);		
				/* Wait until SPI is not busy anymore */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_BSY) == SET);
			}
			break;
		case 2:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPtr == 0){
				return E_NOT_OK;
			}
			while(DataBufferPtr != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);		// Kiem tra xem thanh ghi co bi rong 0 (data truyen di dc thi se bi rong)
				/* Send SPIx data */
				SPI_I2S_SendData(SPIx, *DataBufferPtr++);		// ghi vao thanh ghi SPI tung byte
				/* Wait until SPI is not busy anymore */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_BSY) == SET);
			}
			break;
		case 3:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPtr == 0){
				return E_NOT_OK;
			}
			while(DataBufferPtr != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);		// Kiem tra xem thanh ghi co bi rong 0 (data truyen di dc thi se bi rong)
				/* Send SPIx data */
				SPI_I2S_SendData(SPIx, *DataBufferPtr++);		// ghi vao thanh ghi SPI tung byte
				/* Wait until SPI is not busy anymore */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_BSY) == SET);
			}
			break;
	}
}

Std_ReturnType Spi_ReadIB (Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPointer){
	switch(Channel){
		case 1:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPointer == 0){
				return E_NOT_OK;
			}
			while(*DataBufferPointer != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);		// Kiem tra xem thanh ghi co bi rong 0 (data truyen di dc thi se bi rong)
				/* Receive SPIx data */
				*DataBufferPointer++ = SPI_I2S_ReceiveData(SPIx);
			}
			break;
		case 2:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPointer == 0){
				return E_NOT_OK;
			}
			while(*DataBufferPointer != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);		// Kiem tra xem thanh ghi co bi rong 0 (data truyen di dc thi se bi rong)
				/* Receive SPIx data */
				*DataBufferPointer++ = SPI_I2S_ReceiveData(SPIx);
			}
			break;
			case 3:
			// Step 2: Initialize GPIO
			RCC_APB2PeriphClockCmd(SPI_GPIO_RCC, ENABLE);
			// GPIO pins for MOSI, MISO, and SCK
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_MOSI | SPI_PIN_MISO | SPI_PIN_SCK;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
			// GPIO pin for SS
			GPIO_InitStruct.GPIO_Pin = SPI_PIN_SS;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(SPI_GPIO, &GPIO_InitStruct);
		
			if(DataBufferPointer == 0){
				return E_NOT_OK;
			}
			while(*DataBufferPointer != 0){
				/* Wait for SPIx  Tx 0buffer empty */
				while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);		// Kiem tra xem thanh ghi co bi rong 0 (data truyen di dc thi se bi rong)
				/* Receive SPIx data */
				*DataBufferPointer++ = SPI_I2S_ReceiveData(SPIx);
			}
			break;
	}
}

int main(void){
	
}