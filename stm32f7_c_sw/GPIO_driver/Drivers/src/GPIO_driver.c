#include "stm32f767xx.h"

#include "util.h"
#include "GPIO_driver.h"
#include "EXTI_driver.h"

void GPIO_clkCntrl(GPIO_TypeDef *pBaseAddress, UTIL_enableDisable_e enableDisable){
	switch(enableDisable){
	case ENABLE:
		if(pBaseAddress == GPIOA){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; }
		else if(pBaseAddress == GPIOB){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; }
		else if(pBaseAddress == GPIOC){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; }
		else if(pBaseAddress == GPIOD){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; }
		else if(pBaseAddress == GPIOE){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; }
		else if(pBaseAddress == GPIOF){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; }
		else if(pBaseAddress == GPIOG){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN; }
		else if(pBaseAddress == GPIOH){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN; }
		else if(pBaseAddress == GPIOI){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN; }
		else if(pBaseAddress == GPIOJ){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN; }
		else if(pBaseAddress == GPIOK){ RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN; }
		break;
	case DISABLE:
		if(pBaseAddress == GPIOA){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN; }
		else if(pBaseAddress == GPIOB){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN; }
		else if(pBaseAddress == GPIOC){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN; }
		else if(pBaseAddress == GPIOD){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN; }
		else if(pBaseAddress == GPIOE){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN; }
		else if(pBaseAddress == GPIOF){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN; }
		else if(pBaseAddress == GPIOG){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN; }
		else if(pBaseAddress == GPIOH){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN; }
		else if(pBaseAddress == GPIOI){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN; }
		else if(pBaseAddress == GPIOJ){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN; }
		else if(pBaseAddress == GPIOK){ RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN; }
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
			GPIO_handle->pBaseAddress->AFR[0] |= GET_LSB_OF_8BITS(GPIO_handle->config.pinAltFuncMode) << (4 * GPIO_handle->config.pinNumber);

		}else if(GPIO_handle->config.pinNumber >= 8){

			/* NOTE: GPIO Alternate Function High Register */
			GPIO_handle->pBaseAddress->AFR[1] &= ~(GPIO_AFRH_AFRH0_Msk << (4 * (GPIO_handle->config.pinNumber - 8)));
			GPIO_handle->pBaseAddress->AFR[1] |= GET_LSB_OF_8BITS(GPIO_handle->config.pinAltFuncMode) << (4 * (GPIO_handle->config.pinNumber - 8));

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

	if(pBaseAddress == GPIOA){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST; }
	else if(pBaseAddress == GPIOB){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST; }
	else if(pBaseAddress == GPIOC){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST; }
	else if(pBaseAddress == GPIOD){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST; }
	else if(pBaseAddress == GPIOE){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST; }
	else if(pBaseAddress == GPIOF){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOFRST; }
	else if(pBaseAddress == GPIOG){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOGRST; }
	else if(pBaseAddress == GPIOH){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST; }
	else if(pBaseAddress == GPIOI){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOIRST; }
	else if(pBaseAddress == GPIOJ){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOJRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOJRST; }
	else if(pBaseAddress == GPIOK){ RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOKRST; RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOKRST; }

}

UTIL_setReset_e GPIO_readPin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber){

	return (pBaseAddress->IDR & (GPIO_IDR_IDR_0 << pinNumber)) ? (SET) : (RESET);

}

uint16_t GPIO_readPort(GPIO_TypeDef *pBaseAddress){

	return (uint16_t)(pBaseAddress->IDR);

}

void GPIO_writePin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber, UTIL_setReset_e UTIL_setReset){

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
