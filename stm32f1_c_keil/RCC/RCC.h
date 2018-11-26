#ifndef __RCC_H
#define __RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum{
	TIM2_EN 	= 0,
	TIM3_EN 	= 1,
	TIM4_EN 	= 2,
	TIM5_EN 	= 3,
	TIM6_EN 	= 4,
	TIM7_EN 	= 5,
	TIM12_EN 	= 6,
	TIM13_EN 	= 7,
	TIM14_EN 	= 8,
	WWDG_EN 	= 11,
	SPI2_EN 	= 14,
	SPI3_EN 	= 15,
	USART2_EN = 17,
	USART3_EN = 18,
	UART4_EN 	= 19,
	UART5_EN 	= 20,
	I2C1_EN 	= 21,
	I2C2_EN 	= 22,
	USB_EN 		= 23,
	CAN_EN 		= 25,
	BKP_EN 		= 27,
	PWR_EN 		= 28,
	DAC_EN 		= 29,
}APB1Peripheral_t;

/* // fill this enum
typedef enum{

}APB2Peripherals_t;
*/

extern uint8_t enableAPB1Peripheral(APB1Peripheral_t APB1Peripheral);
extern uint8_t disableAPB1Peripheral(APB1Peripheral_t APB1Peripheral);

#ifdef __cplusplus
}
#endif

#endif /* __RCC_H */