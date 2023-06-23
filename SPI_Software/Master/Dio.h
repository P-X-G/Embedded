#ifndef __DIO_H
#define __DIO_H

#include "stm32f10x.h"

#define SCK DIO_CHANNEL_PA0
#define MISO DIO_CHANNEL_PA1
#define MOSI DIO_CHANNEL_PA2
#define SS DIO_CHANNEL_PA3

typedef enum{
	//GPIOA
	DIO_CHANNEL_PA0,
	DIO_CHANNEL_PA1,
	DIO_CHANNEL_PA2,
	DIO_CHANNEL_PA3,
	DIO_CHANNEL_PA4,
	DIO_CHANNEL_PA5,
	DIO_CHANNEL_PA6,
	DIO_CHANNEL_PA7,
	DIO_CHANNEL_PA8,
	DIO_CHANNEL_PA9,
	DIO_CHANNEL_PA10,
	DIO_CHANNEL_PA11,
	DIO_CHANNEL_PA12,
	//DIO_CHANNEL_PA13,
	//DIO_CHANNEL_PA14,
	DIO_CHANNEL_PA15,
	//GPIOB
	DIO_CHANNEL_PB0,
	DIO_CHANNEL_PB1,
	//DIO_CHANNEL_PB2,
	DIO_CHANNEL_PB3,
	DIO_CHANNEL_PB4,
	DIO_CHANNEL_PB5,
	DIO_CHANNEL_PB6,
	DIO_CHANNEL_PB7,
	DIO_CHANNEL_PB8,
	DIO_CHANNEL_PB9,
	DIO_CHANNEL_PB10,
	DIO_CHANNEL_PB11,
	DIO_CHANNEL_PB12,
	DIO_CHANNEL_PB13,
	DIO_CHANNEL_PB14,
	DIO_CHANNEL_PB15,
	//GPIOC
	DIO_CHANNEL_PC13,
	DIO_CHANNEL_PC14,
	DIO_CHANNEL_PC15
}Dio_ChannelType;

typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_LevelType;

void Dio_WriteChannel(Dio_ChannelType channelID, Dio_LevelType level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelID);

void config(void);

void SPI_init(void);
void Clock(void);
void SPI_Soft_Transmit(uint8_t mData);
uint8_t SPI_Soft_Receive(void);

#endif