#ifndef __DIO_H
#define __DIO_H

#include "stm32f10x.h"
#include <setjmp.h>

#define LED1 DIO_CHANNEL_PA2
#define LED2 DIO_CHANNEL_PB5
#define LED3 DIO_CHANNEL_PC14

#define BTN1 DIO_CHANNEL_PA5
#define BTN2 DIO_CHANNEL_PA6
#define BTN3 DIO_CHANNEL_PA7


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

void BinkLed(int n);
void ChaseLed(int n);
void OffLed();

void delay_n(int n);
void delay_10ms(int n);

void run();

#endif