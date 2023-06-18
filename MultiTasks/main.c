#include "Dio.h"
#include "task.h"


int main(void){

	config();
	
	// Initialize timer interrupt
	TIM2_INT_Init();
	
	Tasks task1 = {&led1, milis(), 500};
	Tasks	task2 = {&led2, milis(), 1000};
	Tasks	task3 = {&led3, milis(), 2000};
	Tasks	task4 = {&led4, milis(), 4000};
	
	while(1){
		MultiTasks(&task1);
		MultiTasks(&task2);
		MultiTasks(&task3);
		MultiTasks(&task4);
	}
}