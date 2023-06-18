#include "Dio.h"
#include "delay.h"


int main(void){
	// Initialize LED as push-pull output
	config();
	
	// Initialize timer interrupt
	TIM2_INT_Init();
	
	while(1){
		run();
	}
}