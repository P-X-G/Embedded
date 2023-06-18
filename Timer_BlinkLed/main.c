#include "Dio.h"
#include "delay.h"

int main(void){
	// Initialize LED as push-pull output
	config();
	
	// Initialize timer interrupt
	TIM2_INT_Init();
	
	while(1){
		Dio_WriteChannel(DIO_CHANNEL_PA2, STD_HIGH);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PA2, STD_LOW);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PB5, STD_HIGH);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PB5, STD_LOW);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PC14, STD_HIGH);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PC14, STD_LOW);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PC13,STD_LOW);
		DelayMs(500);
		Dio_WriteChannel(DIO_CHANNEL_PC13,STD_HIGH);
		DelayMs(500);
	}
}



