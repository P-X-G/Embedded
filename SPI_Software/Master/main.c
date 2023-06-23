#include "Dio.h"
#include "delay.h"

void SPI_init(void){
	Dio_WriteChannel(SCK,STD_LOW);
	Dio_WriteChannel(MOSI, STD_LOW);
	Dio_WriteChannel(SS, STD_HIGH);
}

void Clock(void){
	Dio_WriteChannel(SCK, STD_HIGH);
	DelayMs(100);
	Dio_WriteChannel(SCK, STD_LOW);
	DelayMs(100);
}

void SPI_Soft_Transmit(uint8_t mData){
	uint8_t i = 0;
	Dio_WriteChannel(SS, STD_LOW);
	
	for(i = 0; i < 8; i++){				
		if((mData&0x80) != 0){
			Dio_WriteChannel(MOSI, STD_HIGH);
		}else{									
			Dio_WriteChannel(MOSI, STD_LOW);
		}
		Clock();												
		mData = mData << 1;			
	}
	Dio_WriteChannel(SS,STD_HIGH);	
}

uint8_t SPI_Soft_Receive(void){
	uint8_t sData = 0x00, i = 0;
	while(i < 8){
		if(Dio_ReadChannel(SCK) == STD_HIGH){
			sData = sData << 1; 				
			sData = sData | Dio_ReadChannel(MOSI); 				
		}else{
			i++;
		}
	}
	return sData;
}

int main(void){

	config();
	
	// Initialize timer interrupt
	TIM2_INT_Init();
	
  SPI_init();
  Clock();
	
	while(1){	
		static uint8_t spiMasterTX= 0x00000001;
		
		Dio_WriteChannel(SS,STD_LOW);
		SPI_Soft_Transmit(spiMasterTX);
		Dio_WriteChannel(SS,STD_HIGH);
		spiMasterTX++;
		DelayMs(1000);
		if(spiMasterTX == 10) spiMasterTX = 0x00000001;
	}
}