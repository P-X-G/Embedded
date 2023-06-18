#include "Dio.h"

void config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);
}

void Dio_WriteChannel(Dio_ChannelType channelID, Dio_LevelType level){
	GPIO_TypeDef * gpioPort;
	uint16_t gpioPin;
	switch(channelID){
		// case GPIOA:
		case DIO_CHANNEL_PA0:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_0;				
			break;
		case DIO_CHANNEL_PA1:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_1;				
			break;
		case DIO_CHANNEL_PA2:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_2;				
			break;
		case DIO_CHANNEL_PA3:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_3;				
			break;
		case DIO_CHANNEL_PA4:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_4;				
			break;
		case DIO_CHANNEL_PA5:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_5;				
			break;
		case DIO_CHANNEL_PA6:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_6;				
			break;
		case DIO_CHANNEL_PA7:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_7;				
			break;
		case DIO_CHANNEL_PA8:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_8;				
			break;
		//case GPIOB:
		case DIO_CHANNEL_PB0:	
			gpioPort = GPIOB;					
			gpioPin =	GPIO_Pin_0;				
			break;
		case DIO_CHANNEL_PB1:	
			gpioPort = GPIOB;					
			gpioPin =	GPIO_Pin_1;				
			break;
		case DIO_CHANNEL_PB3:	
			gpioPort = GPIOB;					
			gpioPin =	GPIO_Pin_3;				
			break;
		case DIO_CHANNEL_PB4:	
			gpioPort = GPIOB;					
			gpioPin =	GPIO_Pin_4;				
			break;
		case DIO_CHANNEL_PB5:	
			gpioPort = GPIOB;					
			gpioPin =	GPIO_Pin_5;				
			break;
		//case GPIOC:
		case DIO_CHANNEL_PC13:	
			gpioPort = GPIOC;					
			gpioPin =	GPIO_Pin_13;				
			break;
		case DIO_CHANNEL_PC14:	
			gpioPort = GPIOC;					
			gpioPin =	GPIO_Pin_14;				
			break;
		}
		GPIO_InitTypeDef LED;
		LED.GPIO_Pin = gpioPin;
		LED.GPIO_Mode = GPIO_Mode_Out_PP;
		LED.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(gpioPort, &LED);
	
	if(level == STD_LOW) {
		GPIO_ResetBits(gpioPort, gpioPin);
	}else {
		GPIO_SetBits(gpioPort, gpioPin);
	}
}


Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelID){
	GPIO_TypeDef * gpioPort;
	uint16_t gpioPin;
	
	switch(channelID){
		case DIO_CHANNEL_PA5:
			gpioPort = GPIOA;
			gpioPin = GPIO_Pin_5;
			break;
		case DIO_CHANNEL_PA6:
			gpioPort = GPIOA;
			gpioPin = GPIO_Pin_6;
			break;
		case DIO_CHANNEL_PA7:	
			gpioPort = GPIOA;					
			gpioPin =	GPIO_Pin_7;				
			break;
		case DIO_CHANNEL_PB1:
			gpioPort = GPIOB;
			gpioPin = GPIO_Pin_1;
			break;
		case DIO_CHANNEL_PB5:
			gpioPort = GPIOB;
			gpioPin = GPIO_Pin_5;
			break;
		
		GPIO_InitTypeDef BUTTON;
		BUTTON.GPIO_Pin = gpioPin;
		BUTTON.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init(gpioPort, &BUTTON);
	}
	if(GPIO_ReadInputDataBit(gpioPort, gpioPin) == 0){
		return STD_LOW;
	}else{
		return STD_HIGH;
	}
}