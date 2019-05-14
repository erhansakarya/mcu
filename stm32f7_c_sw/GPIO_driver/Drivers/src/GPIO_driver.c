#include "stm32f767xx.h"

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

void GPIO_init(GPIO_handle_s *GPIO_handle);
void GPIO_deInit(GPIO_TypeDef *pBaseAddress);

UTIL_setReset_e GPIO_readPin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber);
uint16_t GPIO_readPort(GPIO_TypeDef *pBaseAddress);
void GPIO_writePin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber, UTIL_setReset_e UTIL_setReset);
void GPIO_writePort(GPIO_TypeDef *pBaseAddress, uint16_t portValue);
void GPIO_togglePin(GPIO_TypeDef *pBaseAddress, uint8_t pinNumber);

void GPIO_irqConfig(uint8_t irqNumber, uint8_t irqGrouping, uint8_t irqPriority, UTIL_enableDisable_e enableDisable);
void GPIO_irqHandler(uint8_t pinNumber);
