/*
 * it.c
 *
 *  Created on: 3 Mar 2019
 *      Author: erhan
 */

#include "stm32f1xx_hal.h"

void SysTick_Handler(void){
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

