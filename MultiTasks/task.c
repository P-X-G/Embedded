#include "Dio.h"
#include "task.h"

void TIM2_INT_Init(void){
	// Init struct
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	// Enable clock for TIM2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// TIM2 initialization for overflow every 500ms
	// Update Event (Hz) = timer_clock / ((TIM_Prescaler + 1) * (TIM_Period + 1))
	// Update Event (Hz) = 72MHz / ((3599 + 1) * (9999 + 1)) = 2Hz (0.5s)
	// 72MHz / 3600 = 20000Hz (1s) <=> 20Hz (1ms) 
	TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
	TIM_TimeBaseInitStruct.TIM_Period = 19;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	// Enable TIM2 interrupt
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	// Start TIM2
	TIM_Cmd(TIM2, ENABLE);
	
	// Nested vectored interrupt settings
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

static uint32_t count = 0;

uint32_t milis(void){
	return count;
}

void TIM2_IRQHandler(void)
{
	// Checks whether the TIM2 interrupt has occurred or not
	if (TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		count++;
		// Clears the TIM2 interrupt pending bit
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}


void MultiTasks(Tasks *task){
	if(milis() - task->time >= task->delay){
		task->func();
		task->time = milis();
	}
}

void led1(void){
	static Dio_LevelType temp = STD_LOW;
	temp = !temp;
	Dio_WriteChannel(LED1, temp);
}

void led2(void){
	static Dio_LevelType temp = STD_LOW;
	temp = !temp; 
	Dio_WriteChannel(LED2, temp);
}

void led3(void){
	static Dio_LevelType temp = STD_LOW;
	temp = !temp; 
	Dio_WriteChannel(LED3, temp);
}

void led4(void){
	static Dio_LevelType temp = STD_LOW;
	temp = !temp; 
	Dio_WriteChannel(LED4, temp);
}