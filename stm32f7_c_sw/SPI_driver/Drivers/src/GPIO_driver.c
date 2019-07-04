#include "stm32f767xx.h"

#include "util.h"
#include "GPIO_driver.h"
#include "EXTI_driver.h"
#include "RCC_driver.h"

void GPIO_clkCntrl(GPIO_TypeDef *pBaseAddress, UTIL_enableDisable_e enableDisable){

	switch(enableDisable){

	case ENABLE:
		if(pBaseAddress == GPIOA){ GPIOA_CLK_EN; }
		else if(pBaseAddress == GPIOB){ GPIOB_CLK_EN; }
		else if(pBaseAddress == GPIOC){ GPIOC_CLK_EN; }
		else if(pBaseAddress == GPIOD){ GPIOD_CLK_EN; }
		else if(pBaseAddress == GPIOE){ GPIOE_CLK_EN; }
		else if(pBaseAddress == GPIOF){ GPIOF_CLK_EN; }
		else if(pBaseAddress == GPIOG){ GPIOG_CLK_EN; }
		else if(pBaseAddress == GPIOH){ GPIOH_CLK_EN; }
		else if(pBaseAddress == GPIOI){ GPIOI_CLK_EN; }
		else if(pBaseAddress == GPIOJ){ GPIOJ_CLK_EN; }
		else if(pBaseAddress == GPIOK){ GPIOK_CLK_EN; }
		break;

	case DISABLE:
		if(pBaseAddress == GPIOA){ GPIOA_CLK_DIS; }
		else if(pBaseAddress == GPIOB){ GPIOB_CLK_DIS; }
		else if(pBaseAddress == GPIOC){ GPIOC_CLK_DIS; }
		else if(pBaseAddress == GPIOD){ GPIOD_CLK_DIS; }
		else if(pBaseAddress == GPIOE){ GPIOE_CLK_DIS; }
		else if(pBaseAddress == GPIOF){ GPIOF_CLK_DIS; }
		else if(pBaseAddress == GPIOG){ GPIOG_CLK_DIS; }
		else if(pBaseAddress == GPIOH){ GPIOH_CLK_DIS; }
		else if(pBaseAddress == GPIOI){ GPIOI_CLK_DIS; }
		else if(pBaseAddress == GPIOJ){ GPIOJ_CLK_DIS; }
		else if(pBaseAddress == GPIOK){ GPIOK_CLK_DIS; }
		break;

	default:
		break;

	}

}

void GPIO_init(GPIO_handle_s *GPIO_handle){

	/* NOTE: GPIO Mode Register */
	GPIO_handle->pBaseAddress->MODER &= ~(GPIO_MODER_MODER0_Msk << (2 * GPIO_handle->config.pinNumber));
	GPIO_handle->pBaseAddress->MODER |= (GPIO_handle->config.pinMode) << (2 * GPIO_handle->config.pinNumber);

	/* NOTE: GPIO Output Type Register */
	GPIO_handle->pBaseAddress->OTYPER &= ~(GPIO_OTYPER_OT_0 << GPIO_handle->config.pinNumber);
	GPIO_handle->pBaseAddress->OTYPER |= (GPIO_handle->config.pinOutType << GPIO_handle->config.pinNumber);

	/* NOTE: GPIO Output Speed Register */
	GPIO_handle->pBaseAddress->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0_Msk << (2 * GPIO_handle->config.pinNumber));
	GPIO_handle->pBaseAddress->OSPEEDR |= (GPIO_handle->config.pinSpeed) << (2 * GPIO_handle->config.pinNumber);

	/* NOTE: GPIO PullUpDown Register */
	GPIO_handle->pBaseAddress->PUPDR &= ~(GPIO_PUPDR_PUPDR0_Msk << (2 * GPIO_handle->config.pinNumber));
	GPIO_handle->pBaseAddress->PUPDR |= (GPIO_handle->config.pinPuPd) << (2 * GPIO_handle->config.pinNumber);

	if(GPIO_ALTERFUNC == GPIO_handle->config.pinMode){

		if(GPIO_handle->config.pinNumber < 8){

			/* NOTE: GPIO Alternate Function Low Register */
			GPIO_handle->pBaseAddress->AFR[0] &= ~(GPIO_AFRL_AFRL0_Msk << (4 * GPIO_handle->config.pinNumber));
			GPIO_handle->pBaseAddress->AFR[0] |= GPIO_handle->config.pinAltFuncMode << (4 * GPIO_handle->config.pinNumber);

		}else if(GPIO_handle->config.pinNumber >= 8){

			/* NOTE: GPIO Alternate Function High Register */
			GPIO_handle->pBaseAddress->AFR[1] &= ~(GPIO_AFRH_AFRH0_Msk << (4 * (GPIO_handle->config.pinNumber - 8)));
			GPIO_handle->pBaseAddress->AFR[1] |= GPIO_handle->config.pinAltFuncMode << (4 * (GPIO_handle->config.pinNumber - 8));

		}

	}

}

UTIL_lockUnlock_e GPIO_lockPort(GPIO_TypeDef *pBaseAddress, uint16_t lockValue){

	uint32_t tempRegVal = 0x00000000U;
	uint16_t tempLCKR;

	tempLCKR = 0x0000U;

	if(pBaseAddress->LCKR >> 16){

		/* NOTE: Lock already */
		return LOCK;

	}else{

		tempRegVal |= (0x00000001U << 16);
		tempRegVal |= lockValue;

		/* NOTE: WR LCKR[16] = '1' + LCKR[15:0] */
		pBaseAddress->LCKR = tempRegVal;

		/* NOTE: WR LCKR[16] = '0' + LCKR[15:0] */
		pBaseAddress->LCKR = lockValue;

		/* NOTE: WR LCKR[16] = '1' + LCKR[15:0] */
		pBaseAddress->LCKR = tempRegVal;

		/* NOTE: RD LCKR */
		tempLCKR = pBaseAddress->LCKR;

		/* NOTE: RD LCKR[16] = '1' it confirms that lock is active*/
		return ((pBaseAddress->LCKR >> 16) & 0x00000001U) ? (LOCKED) : (NOT_LOCKED);

	}

}

void GPIO_deInit(GPIO_TypeDef *pBaseAddress){

	if(pBaseAddress == GPIOA){ GPIOA_RESET; }
	else if(pBaseAddress == GPIOB){ GPIOB_RESET; }
	else if(pBaseAddress == GPIOC){ GPIOC_RESET; }
	else if(pBaseAddress == GPIOD){ GPIOD_RESET; }
	else if(pBaseAddress == GPIOE){ GPIOE_RESET; }
	else if(pBaseAddress == GPIOF){ GPIOF_RESET; }
	else if(pBaseAddress == GPIOG){ GPIOG_RESET; }
	else if(pBaseAddress == GPIOH){ GPIOH_RESET; }
	else if(pBaseAddress == GPIOI){ GPIOI_RESET; }
	else if(pBaseAddress == GPIOJ){ GPIOJ_RESET; }
	else if(pBaseAddress == GPIOK){ GPIOK_RESET; }

}

UTIL_SETRESET_e GPIO_readPin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber){

	return (pBaseAddress->IDR & (GPIO_IDR_IDR_0 << pinNumber)) ? (SET) : (RESET);

}

uint16_t GPIO_readPort(GPIO_TypeDef *pBaseAddress){

	return (uint16_t)(pBaseAddress->IDR);

}

void GPIO_writePin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber, UTIL_SETRESET_e UTIL_setReset){

	switch(UTIL_setReset){

		case SET:
			pBaseAddress->BSRR &= ~(GPIO_BSRR_BR_0 << pinNumber);
			pBaseAddress->BSRR |= GPIO_BSRR_BS_0 << pinNumber;
			break;

		case RESET:
			pBaseAddress->BSRR &= ~(GPIO_BSRR_BS_0 << pinNumber);
			pBaseAddress->BSRR |= GPIO_BSRR_BR_0 << pinNumber;
			break;

		default:
			break;
	}

}

void GPIO_writePort(GPIO_TypeDef *pBaseAddress, uint16_t portValue){

	pBaseAddress->ODR = portValue;

}

void GPIO_togglePin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber){

	pBaseAddress->ODR ^= (GPIO_BSRR_BS_0 << pinNumber);

}

void GPIO_irqConfig(uint8_t irqNumber, uint8_t irqGrouping, uint8_t irqPriority, UTIL_enableDisable_e enableDisable);
void GPIO_irqHandler(uint8_t pinNumber);
