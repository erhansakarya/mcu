#ifndef __UTIL_H
#define __UTIL_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include "stm32f767xx.h"

typedef enum{
	ENABLE = 1,
	DISABLE = 0
}UTIL_enableDisable_e;

typedef enum{
	SET = 1,
	RESET = 0
}UTIL_setReset_e;

#define GET_MSB_OF_16BITS(X) (uint8_t)((X & 0xFF00) >> 8)
#define GET_MSB_OF_8BITS(X)	 (uint8_t)(X & 0xF0)
#define GET_LSB_OF_16BITS(X) (uint8_t)(X & 0x00FF)
#define GET_LSB_OF_8BITS(X)	 (uint8_t)(X & 0x0F)

#endif
