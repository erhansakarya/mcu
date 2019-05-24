#include "stm32f767xx.h"

#include "util.h"
#include "GPIO_driver.h"
#include "EXTI_driver.h"
#include "RCC_driver.h"
#include "SPI_driver.h"

void SPI_clkCntrl(SPI_TypeDef *pBaseAddress, UTIL_enableDisable_e enableDisable){

	switch(enableDisable){

	case ENABLE:
		if(pBaseAddress == SPI1){ SPI1_CLK_EN; }
		else if(pBaseAddress == SPI2){ SPI2_CLK_EN; }
		else if(pBaseAddress == SPI3){ SPI3_CLK_EN; }
		else if(pBaseAddress == SPI4){ SPI4_CLK_EN; }
		break;

	case DISABLE:
		if(pBaseAddress == SPI1){ SPI1_CLK_DIS; }
		else if(pBaseAddress == SPI2){ SPI2_CLK_DIS; }
		else if(pBaseAddress == SPI3){ SPI3_CLK_DIS; }
		else if(pBaseAddress == SPI4){ SPI4_CLK_DIS; }
		break;

	default:
		break;

	}

}

void SPI_init(SPI_handle_s *SPI_handle){



}

void SPI_deInit(SPI_TypeDef *pBaseAddress){

	if(pBaseAddress == SPI1){ SPI1_RESET; }
	else if(pBaseAddress == SPI2){ SPI2_RESET; }
	else if(pBaseAddress == SPI3){ SPI3_RESET; }
	else if(pBaseAddress == SPI4){ SPI4_RESET; }

}
