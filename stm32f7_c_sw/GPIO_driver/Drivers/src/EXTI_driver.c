#include "stm32f767xx.h"

#include "util.h"
#include "GPIO_driver.h"
#include "EXTI_driver.h"

void EXTI_initExtInt(GPIO_handle_s *GPIO_handle, EXTI_handle_s *EXTI_handle){

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	switch(EXTI_handle->config.triggerSelection){

	case RISING:
		EXTI_handle->pBaseAddress->RTSR |= (EXTI_RTSR_TR0 << GPIO_handle->config.pinNumber);
		EXTI_handle->pBaseAddress->FTSR &= ~(EXTI_FTSR_TR0 << GPIO_handle->config.pinNumber);
		break;

	case FALLING:
		EXTI_handle->pBaseAddress->FTSR |= (EXTI_FTSR_TR0 << GPIO_handle->config.pinNumber);
		EXTI_handle->pBaseAddress->RTSR &= ~(EXTI_RTSR_TR0 << GPIO_handle->config.pinNumber);
		break;

	case RISING_FALLING:
		EXTI_handle->pBaseAddress->FTSR |= (EXTI_FTSR_TR0 << GPIO_handle->config.pinNumber);
		EXTI_handle->pBaseAddress->RTSR |= (EXTI_RTSR_TR0 << GPIO_handle->config.pinNumber);
		break;

	default:
		break;

	}

	EXTI_handle->pBaseAddress->IMR |= (EXTI_IMR_MR0 << GPIO_handle->config.pinNumber);

	uint8_t EXTICRx = GPIO_handle->config.pinNumber / 4;
	uint8_t EXTIx = GPIO_handle->config.pinNumber % 4;

	SYSCFG->EXTICR[EXTICRx] |= (GET_PORT_ADDR_VALUE(GPIO_handle->pBaseAddress) << (4 * EXTIx));

}

void EXTI_configPriority(EXTI_handle_s *EXTI_handle, uint32_t priority){

	NVIC_SetPriority((IRQn_Type)EXTI_handle->config.lineSelect, priority);

}

void EXTI_enableDisable(EXTI_handle_s *EXTI_handle, UTIL_enableDisable_e enableDisable){

	/* WARNING: EXTI_IMR register'da da interrupt'ın kapatılması gerekmiyor mu? */

	switch(enableDisable){

	case ENABLE:
		NVIC_EnableIRQ((IRQn_Type)EXTI_handle->config.lineSelect);
		break;

	case DISABLE:
		NVIC_DisableIRQ((IRQn_Type)EXTI_handle->config.lineSelect);
		break;

	default:
		break;

	}

}

void EXTI_interruptHandler(uint8_t pinNumber){

	/* NOTE: Clear the PR bit */
	if(EXTI->PR & (0x00000001U << pinNumber)){

		EXTI->PR |= (0x00000001U << pinNumber);

	}

}
