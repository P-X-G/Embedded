#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"

void TIM2_INT_Init(void);
void TIM2_IRQHandler(void);
void DelayMs(uint32_t ms);

#endif