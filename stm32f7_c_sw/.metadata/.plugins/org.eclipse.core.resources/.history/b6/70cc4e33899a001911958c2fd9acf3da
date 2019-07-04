#ifndef __SPI_DRIVER_H
#define __SPI_DRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

#include "stm32f767xx.h"

#include "util.h"

typedef enum{
	SPI_DEVMODE_SLAVE	= 0,
	SPI_DEVMODE_MASTER 	= 1
}SPI_DEVMODE_e;

typedef enum{
	SPI_BUSCONFIG_FULLDUPLEX,
	SPI_BUSCONFIG_HALFDUPLEX,
	SPI_BUSCONFIG_SIMPLEXTXONLY,
	SPI_BUSCONFIG_SIMPLEXRXONLY
}SPI_BUSCONFIG_e;

typedef enum{
	SPI_CLKSPEED_DIV2	= 0x00,
	SPI_CLKSPEED_DIV4 	= 0x01,
	SPI_CLKSPEED_DIV8 	= 0x02,
	SPI_CLKSPEED_DIV16 	= 0x03,
	SPI_CLKSPEED_DIV32 	= 0x04,
	SPI_CLKSPEED_DIV64 	= 0x05,
	SPI_CLKSPEED_DIV128 = 0x06,
	SPI_CLKSPEED_DIV256 = 0x07
}SPI_CLKSPEED_e;

typedef enum{
	SPI_DATAFORMAT_4BIT 	= 0x03,
	SPI_DATAFORMAT_5BIT 	= 0x04,
	SPI_DATAFORMAT_6BIT 	= 0x05,
	SPI_DATAFORMAT_7BIT 	= 0x06,
	SPI_DATAFORMAT_8BIT 	= 0x07,
	SPI_DATAFORMAT_9BIT 	= 0x08,
	SPI_DATAFORMAT_10BIT 	= 0x09,
	SPI_DATAFORMAT_11BIT 	= 0x0A,
	SPI_DATAFORMAT_12BIT 	= 0x0B,
	SPI_DATAFORMAT_13BIT 	= 0x0C,
	SPI_DATAFORMAT_14BIT 	= 0x0D,
	SPI_DATAFORMAT_15BIT 	= 0x0E,
	SPI_DATAFORMAT_16BIT 	= 0x0F
}SPI_DATAFORMAT_e;

typedef enum{
	SPI_CPOL_LOW 	= 0,
	SPI_CPOL_HIGH 	= 1
}SPI_CPOL_e;

typedef enum{
	SPI_CPHA_LOW 	= 0,
	SPI_CPHA_HIGH 	= 1
}SPI_CPHA_e;

typedef enum{
	SPI_SSM_DIS	= 0,	/* NOTE: Software slave management disabled */
	SPI_SSM_EN	= 1		/* NOTE: Software slave management enabled */
}SPI_SSM_e;

typedef enum{
	SPI_FLAG_BUSY	= SPI_SR_BSY,
	SPI_FLAG_TXE	= SPI_SR_TXE,
	SPI_FLAG_RXNE	= SPI_SR_RXNE
}SPI_FLAG_e;

typedef struct{
	SPI_DEVMODE_e		SPI_devMode;	/* NOTE: Master or Slave mode selection */
	SPI_BUSCONFIG_e 	SPI_busConfig;	/* NOTE: Full Duplex, Half Duplex, Simplex TX_ONLY, Simplex RX_ONLY */
	SPI_CLKSPEED_e		SPI_clkSpeed;	/* NOTE: Baudrate Control Value selection */
	SPI_DATAFORMAT_e	SPI_dataFormat;	/* NOTE: 8 or 16-bit selection */
	SPI_CPOL_e 			SPI_cpol;		/* NOTE: Clock polarity selection */
	SPI_CPHA_e 			SPI_cpha;		/* NOTE: Clock phase selection */
	SPI_SSM_e 			SPI_ssm;		/* NOTE: Slave select management in software or hardware mode */
}SPI_config_s;

typedef struct{
	SPI_TypeDef *pBaseAddress;
	SPI_config_s config;
}SPI_handle_s;

extern void SPI_clkCntrl(SPI_TypeDef *pBaseAddress, UTIL_enableDisable_e enableDisable);

extern void SPI_init(SPI_handle_s *SPI_handle);
extern void SPI_deInit(SPI_TypeDef *pBaseAddress);

#endif
