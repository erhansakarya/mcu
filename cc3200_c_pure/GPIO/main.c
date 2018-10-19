#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// includes for hardware
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_prcm.h"
#include "hw_gpio.h"

#if 0
void boardInit(void)
{
   // set port A1.1 as output (RED LED GPIO_09)
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DIR)|= 0x00000002 ;
   // switch off the pin
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000002<<2)) = 0x00000000;
   // set port A1.2 as output (YELLOW LED GPIO_10)
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DIR)|= 0x00000004 ;
   // switch off the pin
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000004<<2)) = 0x00000000;
   // set port A1.3 as output (GREEN LED GPIO_11)
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DIR)|= 0x00000008 ;
   // switch off the pin
   HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000008<<2)) = 0x00000000;
}
#endif

#if 0
void delayByCount(float tellerwaarde)
{
    int teller = 0;
    while (teller < tellerwaarde)
    {
        teller++;
    }
}
#endif

/*
 * main.c
 */
void main(void)
{
    
#if 0
    boardInit();
    while(1)
    {
        //Blink RED
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000002<<2)) = 0X00000002;
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000002<<2)) = 0X00000000;
        //BLINK YELLOW
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000004<<2)) = 0X00000004;
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000004<<2)) = 0X00000000;
        //Blink GREEN
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000008<<2)) = 0X00000008;
        delayByCount(200000);
        HWREG(GPIOA1_BASE + GPIO_O_GPIO_DATA + (0x00000008<<2)) = 0X00000000;
   }
#endif
}