#include <stdint.h>

#include "stm32f10x.h"

#include "RCC.h"

#include "utils.h"

/*
RCC_CFGR_SW_HSI	HSI selected as system clock
RCC_CFGR_SW_HSE	HSE selected as system clock
RCC_CFGR_SW_PLL	PLL selected as system clock
if the Clock Security System is enabled ???
*/
uint8_t setSystemClkSource(uint32_t systemClkSource){
	assert_param(IS_RCC_SYSCLK_SOURCE(systemClkSource));
	
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	uint32_t temp = 0;
	
	temp = pRCC->CFGR;
	temp &= CFGR_SW_Mask;
	temp |= systemClkSource;
	
	pRCC->CFGR |= temp;
}

/*
RCC_CFGR_MCO_NOCLOCK	No clock
RCC_CFGR_MCO_SYSCLK 	System clock selected as MCO source
RCC_CFGR_MCO_HSI    	HSI clock selected as MCO source
RCC_CFGR_MCO_HSE    	HSE clock selected as MCO source
RCC_CFGR_MCO_PLL    	PLL clock divided by 2 selected as MCO source
When the System Clock is selected to output to the MCO pin, make sure that this clock does not exceed 50 MHz (the maximum IO speed). 
*/
uint8_t setMcoClkSource(uint32_t mcoClkSource){
	assert_param(IS_MCO_CLK_SOURCE(mcoClkSource));
	
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	
	*(__IO uint8_t *) CFGR_BYTE4_ADDRESS |= GET_FIRST_MSB_OF_32BIT(mcoClkSource);
	
}

/*
	RCC_APB1ENR_TIM2EN
	RCC_APB1ENR_TIM3EN
	RCC_APB1ENR_TIM4EN
	RCC_APB1ENR_TIM5EN
	RCC_APB1ENR_TIM6EN 	
	RCC_APB1ENR_TIM7EN 	
	RCC_APB1ENR_TIM12EN	
	RCC_APB1ENR_TIM13EN	
	RCC_APB1ENR_TIM14EN	
	RCC_APB1ENR_WWDGEN
	RCC_APB1ENR_SPI2EN
	RCC_APB1ENR_SPI3EN
	RCC_APB1ENR_USART2EN
	RCC_APB1ENR_USART3EN
	RCC_APB1ENR_UART4EN
	RCC_APB1ENR_UART5EN
	RCC_APB1ENR_I2C1EN 
	RCC_APB1ENR_I2C2EN 
	RCC_APB1ENR_USBEN	
	RCC_APB1ENR_CANEN 	
	RCC_APB1ENR_BKPEN 	
	RCC_APB1ENR_PWREN 	
	RCC_APB1ENR_DACEN
*/ 	
uint8_t controlAPB1PeriphClk(uint32_t APB1Peripheral, FunctionalState state){
	
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	
	if(state){
			pRCC->APB1ENR |= APB1Peripheral;
	}else{
			pRCC->APB1ENR &= ~APB1Peripheral;
	}
	
	return 0;
}

/*
	RCC_APB2ENR_AFIOEN 	
	RCC_APB2ENR_GPIOAEN	
	RCC_APB2ENR_GPIOBEN	
	RCC_APB2ENR_GPIOCEN	
	RCC_APB2ENR_GPIODEN	
	RCC_APB2ENR_GPIOEEN	
	RCC_APB2ENR_GPIOFEN	
	RCC_APB2ENR_GPIOGEN	
	RCC_APB2ENR_ADC1EN	
	RCC_APB2ENR_ADC2EN	
	RCC_APB2ENR_TIM1EN	
	RCC_APB2ENR_SPI1EN	
	RCC_APB2ENR_TIM8EN	
	RCC_APB2ENR_USART1EN
	RCC_APB2ENR_ADC3EN	
	RCC_APB2ENR_TIM9EN	
	RCC_APB2ENR_TIM10EN	
	RCC_APB2ENR_TIM11EN	
*/
uint8_t controlAPB2PeriphClk(uint32_t APB2Peripheral, FunctionalState state){
	
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	
	if(state){
			pRCC->APB2ENR |= APB2Peripheral;
	}else{
			pRCC->APB2ENR &= ~APB2Peripheral;
	}
	
	return 0;
}

/*
	RCC_AHBENR_DMA1EN 
	RCC_AHBENR_DMA2EN
	RCC_AHBENR_SRAMEN
	RCC_AHBENR_FLITFEN
	RCC_AHBENR_CRCEN	
	RCC_AHBENR_FSMCEN
	RCC_AHBENR_SDIOEN
*/
uint8_t controlAHBPeriphClk(uint32_t AHBPeripheral, FunctionalState state){
	
	RCC_TypeDef *pRCC = (RCC_TypeDef *)RCC_BASE;
	
	if(state){
			pRCC->AHBENR |= AHBPeripheral;
	}else{
			pRCC->AHBENR &= ~AHBPeripheral;
	}
	
	return 0;
}
