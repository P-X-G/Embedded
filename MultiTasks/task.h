#ifndef __TASK_H
#define __TASK_H

#include "stm32f10x.h"

typedef struct{
	void (*func)(void);
	uint32_t time;
	uint32_t delay;
}Tasks;


void TIM2_INT_Init(void);
uint32_t milis(void);
void TIM2_IRQHandler(void);
void MultiTasks(Tasks *task);

void led1(void);
void led2(void);
void led3(void);
void led4(void);

#endif