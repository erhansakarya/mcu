#include <stdint.h>

#include "stm32f10x.h"

#include "RCC.h"

int main(void){
	
	// address of RCC is 0x4002 1000
	controlAPB1PeriphClk(RCC_APB1ENR_TIM2EN, ENABLE);		// offset of RCC_APB1ENR register is 0x1C, TIM2_EN is 0. bit 
	controlAPB1PeriphClk(RCC_APB1ENR_TIM3EN, ENABLE);		// offset of RCC_APB1ENR register is 0x1C, TIM3_EN is 1. bit
	controlAPB1PeriphClk(RCC_APB1ENR_TIM2EN, DISABLE);	 
	controlAPB1PeriphClk(RCC_APB1ENR_TIM3EN, DISABLE);
	
	controlAPB2PeriphClk(RCC_APB2ENR_ADC1EN, ENABLE);		// offset of RCC_APB2ENR register is 0x18, ADC1_EN is 9. bit 
	controlAPB2PeriphClk(RCC_APB2ENR_ADC1EN, DISABLE);
	
	controlAHBPeriphClk(RCC_AHBENR_DMA1EN, ENABLE);			// offset of RCC_AHBENR register is 0x14, DMA1_EN is 0. bit
	controlAHBPeriphClk(RCC_AHBENR_DMA1EN, DISABLE);
	
	return (0);
}