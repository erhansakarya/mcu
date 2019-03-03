/*
 * msp.c
 *
 *  Created on: 3 Mar 2019
 *      Author: erhan
 */

#include "stm32f1xx_hal.h"

void HAL_MspInit(void)
{
	// Here will do low level processor specific inits.

	// 1. set up the priority grouping of the arm cortex m3 processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// 2. enable the required system exceptions of the arm cortex m3 processor
	// System Handler Control and State Register on ARM Cortex M3 User Guide
	// Activate UsageFault, BusFault, and MemFault System Exceptions.
	SCB->SHCSR |= 0x07 << 16;

	// 3. configure the priority for the system exceptions
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef gpio_uart;

	// Here will do low level inits for USART2 peripheral.

	// 1. enable the clock for the USART2&GPIOA peripheral
	__HAL_RCC_USART2_CLK_ENABLE();	// this is a macro
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//__HAL_RCC_AFIO_CLK_ENABLE();
	// 2. pin muxing configurations
	gpio_uart.Pin = GPIO_PIN_2;
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	//gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio_uart);

	//gpio_uart.Pin = GPIO_PIN_3;
	//HAL_GPIO_Init(GPIOA, &gpio_uart);
	// 3. enable the IRQ and set up the priority (NVIC settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
