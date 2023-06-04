//#include "stm32f10x.h"
#include "Dio.h"


void config(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);
}


void delay(){
	uint32_t i;
	for(i = 0; i < 1000000; i++);
}


int main(void){

	config();
	
	while(1){
		Dio_WriteChannel(DIO_CHANNEL_PA2, STD_HIGH);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PA2, STD_LOW);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PB5, STD_HIGH);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PB5, STD_LOW);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PC14, STD_HIGH);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PC14, STD_LOW);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PC13,STD_LOW);
		delay();
		Dio_WriteChannel(DIO_CHANNEL_PC13,STD_HIGH);
		delay();
	}
}

