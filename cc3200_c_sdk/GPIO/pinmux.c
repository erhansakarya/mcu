#include "pinmux.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "pin.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "prcm.h"

//*****************************************************************************
void
PinMuxConfig(void)
{
      
    /*
    Leds: Red(GPIO_09), Yellow(GPIO_10), Green(GPIO_11)
    * gpio numbers of leds are 9, 10, and 11. Each of GPIO ports has 8-bits (0...7).
    * Therefore, GPIOA1 port has these bits.
    Buttons: SW2(GPIO_22) and SW3(GPIO_13)
    * gpio numbers of buttons are 22 and 13.
    * Therefore, SW2 is in GPIOA2 and SW3 is in GPIOA1
    */
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1 | PRCM_GPIOA2, PRCM_RUN_MODE_CLK);  // Enable Peripheral Clocks

    MAP_PinTypeGPIO(PIN_64, PIN_MODE_0, false);                                 // Configure for GPIOOutput
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x2, GPIO_DIR_MODE_OUT);                    // Configure for GPIO9 (2^(9-8))

    MAP_PinTypeGPIO(PIN_01, PIN_MODE_0, false);                                 // Configure for GPIOOutput
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x4, GPIO_DIR_MODE_OUT);                    // Configure for GPIO10 (2^(10-8))

    MAP_PinTypeGPIO(PIN_02, PIN_MODE_0, false);                                 // Configure for GPIOOutput
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x8, GPIO_DIR_MODE_OUT);                    // Configure for GPIO11 (2^(11-8))
    
    //MAP_PinTypeGPIO(PIN_15, PIN_MODE_0, false);                                 // Configure SW2(GPIO22) as GPIO and Push-Pull
    //MAP_GPIODirModeSet(GPIOA2_BASE, 0x80, GPIO_DIR_MODE_IN);                    // Configure for GPIO22 (2^(22-15))

    MAP_PinTypeGPIO(PIN_04, PIN_MODE_0, false);                                 // Configure SW3(GPIO13) as GPIO and Push-Pull
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x20, GPIO_DIR_MODE_IN);                    // Configure for GPIO13 (2^(13-8))
    
    /* or you can use
    void GPIO_IF_GetPortNPin(unsigned char ucPin, unsigned int *puiGPIOPort, unsigned char *pucGPIOPin);
    function in the gpio_if.c source file.
    */
    
}
