/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f767xx.h"

#include "util.h"
#include "GPIO_driver.h"

#define LED_PORT 	GPIOB

#define BUTTON_PORT	GPIOC

typedef enum{
	LED_1_PIN = 0,
	LED_2_PIN = 7,
	LED_3_PIN = 14
}led_pin_number_e;

#define BUTTON_PIN	13

static void initLED(led_pin_number_e ledNumber);
static void initButton(void);
static void controlLED(led_pin_number_e ledNumber, UTIL_setReset_e setReset);
static UTIL_setReset_e getButtonState(void);

int main(void)
{

	initLED(LED_1_PIN);
	initLED(LED_2_PIN);
	initLED(LED_3_PIN);

	initButton();

	controlLED(LED_1_PIN, SET);
	controlLED(LED_2_PIN, SET);
	controlLED(LED_3_PIN, SET);

	controlLED(LED_1_PIN, RESET);
	controlLED(LED_2_PIN, RESET);
	controlLED(LED_3_PIN, RESET);

	for(;;){
		controlLED(LED_3_PIN, getButtonState());
	}

}

static void initLED(led_pin_number_e ledNumber){

	GPIO_handle_s GPIO_handle;

	GPIO_handle.pBaseAddress 			= LED_PORT;
	GPIO_handle.config.pinNumber 		= ledNumber;
	GPIO_handle.config.pinMode 			= GPIO_OUTPUT;
	GPIO_handle.config.pinSpeed 		= GPIO_MEDIUM;
	GPIO_handle.config.pinPuPd 			= GPIO_NOPUPD;
	GPIO_handle.config.pinOutType 		= GPIO_PP;
	GPIO_handle.config.pinAltFuncMode 	= 0x00U;

	GPIO_clkCntrl(GPIO_handle.pBaseAddress, ENABLE);

	GPIO_init(&GPIO_handle);

}

static void initButton(void){

	GPIO_handle_s GPIO_handle;

	GPIO_handle.pBaseAddress 			= BUTTON_PORT;
	GPIO_handle.config.pinNumber 		= BUTTON_PIN;
	GPIO_handle.config.pinMode 			= GPIO_INPUT;
	GPIO_handle.config.pinSpeed 		= GPIO_MEDIUM;
	GPIO_handle.config.pinPuPd 			= GPIO_NOPUPD;
	GPIO_handle.config.pinOutType 		= GPIO_OD;
	GPIO_handle.config.pinAltFuncMode 	= 0x00U;

	GPIO_clkCntrl(GPIO_handle.pBaseAddress, ENABLE);

	GPIO_init(&GPIO_handle);

}

static void controlLED(led_pin_number_e ledNumber, UTIL_setReset_e setReset){

	GPIO_writePin(LED_PORT, ledNumber, setReset);

}

static UTIL_setReset_e getButtonState(void){

	GPIO_readPin(BUTTON_PORT, BUTTON_PIN);

}
