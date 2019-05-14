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

#endif
