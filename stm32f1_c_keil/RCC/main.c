#include <stdint.h>

#include "stm32f10x.h"

#include "RCC.h"

int main(void){
	
	enableAPB1Peripheral(TIM2_EN);
	disableAPB1Peripheral(TIM2_EN);
	
	return (0);
}