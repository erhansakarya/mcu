#ifndef __SPI_DRIVER_H
#define __SPI_DRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include "stm32f767xx.h"

#include "util.h"

typedef struct{
	uint8_t SPI_devMode;
	uint8_t SPI_busConfig;
	uint8_t SPI_clkSpeed;
	uint8_t SPI_dataFormat;
	uint8_t SPI_cpol;	/* NOTE: Bunları sadece mode değişkeni ile ayarla, iki tane ayrı değişken olmasın. */
	uint8_t SPI_cpha;
	uint8_t SPI_ssm;
}SPI_config_s;

typedef struct{
	SPI_TypeDef *pBaseAddress;
	SPI_config_s config;
}SPI_handle_s;

extern void SPI_clkCntrl(SPI_TypeDef *pBaseAddress, UTIL_enableDisable_e enableDisable);

extern void SPI_init(SPI_handle_s *SPI_handle);
extern void SPI_deInit(SPI_TypeDef *pBaseAddress);

#endif
