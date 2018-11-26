#include <stdint.h>

#include "stm32f10x.h"

#include "RCC.h"

uint8_t enableAPB1Peripheral(APB1Peripheral_t APB1Peripheral){
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	pRCC->APB1ENR |= (1 << APB1Peripheral);
	
	return 0;
}

uint8_t disableAPB1Peripheral(APB1Peripheral_t APB1Peripheral){
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	
	APB1Peripheral = ~APB1Peripheral;
	pRCC->APB1ENR &= (0 << APB1Peripheral);
	
	return 0;
}

/*
uint8_t enableAPB2Peripheral(APB2Peripheral ){

	return 0;
}
*/