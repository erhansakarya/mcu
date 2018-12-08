#ifndef __RCC_H
#define __RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

#include "stm32f10x.h"

#define CFGR_SW_Mask              ((uint32_t)0xFFFFFFFC)

#define CFGR_BYTE4_ADDRESS        ((uint32_t)0x40021007)


#define IS_RCC_SYSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_CFGR_SW_HSI) || \
                                      ((SOURCE) == RCC_CFGR_SW_HSE) || \
                                      ((SOURCE) == RCC_CFGR_SW_PLL))
#define	IS_MCO_CLK_SOURCE(SOURCE)			(((SOURCE) == RCC_CFGR_MCO_NOCLOCK) || 	\
                                      ((SOURCE) == RCC_CFGR_MCO_SYSCLK) 	|| 	\
                                      ((SOURCE) == RCC_CFGR_MCO_HSI)			||	\
																			((SOURCE) == RCC_CFGR_MCO_HSE)			||	\
																			((SOURCE) == RCC_CFGR_MCO_PLL))

extern uint8_t setSystemClkSource(uint32_t systemClkSource);
extern uint8_t setMcoClkSource(uint32_t mcoClkSource);
extern uint8_t controlAPB1PeriphClk(uint32_t APB1Peripheral, FunctionalState state);
extern uint8_t controlAPB2PeriphClk(uint32_t APB2Peripheral, FunctionalState state);
extern uint8_t controlAHBPeriphClk(uint32_t AHBPeripheral, FunctionalState state);


#ifdef __cplusplus
}
#endif

#endif /* __RCC_H */