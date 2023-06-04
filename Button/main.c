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
		run();
	}
}

