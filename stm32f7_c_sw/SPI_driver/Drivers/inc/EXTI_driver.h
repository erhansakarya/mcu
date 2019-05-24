#ifndef __EXTI_DRIVER_H
#define __EXTI_DRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include "stm32f767xx.h"

typedef enum{
	RISING,
	FALLING,
	RISING_FALLING
}EXTI_triggerSelection_e;

typedef enum{
	_EXTI0_IRQn                  = 6,
	_EXTI1_IRQn                  = 7,
	_EXTI2_IRQn                  = 8,
	_EXTI3_IRQn                  = 9,
	_EXTI4_IRQn                  = 10,
	_EXTI9_5_IRQn                = 23,
	_EXTI15_10_IRQn              = 40,
}EXTI_lineSelect_e;

typedef struct{
	EXTI_triggerSelection_e triggerSelection;
	EXTI_lineSelect_e lineSelect;
}EXTI_config_s;

typedef struct{
	EXTI_TypeDef	*pBaseAddress;
	EXTI_config_s	config;
}EXTI_handle_s;

extern void EXTI_initExtInt(GPIO_handle_s *GPIO_handle, EXTI_handle_s *EXTI_handle);
void EXTI_configPriority(EXTI_handle_s *EXTI_handle, uint32_t priortiy);
void EXTI_enableDisable(EXTI_handle_s *EXTI_handle, UTIL_enableDisable_e enableDisable);

#endif
