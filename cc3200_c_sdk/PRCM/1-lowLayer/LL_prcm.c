/** @file rcc.c
*
* @brief
* This module manages reset&clock peripherals
*
* @par
*
*/

// Standard includes
#include <stdio.h>

// Driverlib includes
#include "hw_types.h"                                                           // Includes data types.
#include "hw_ints.h"                                                            // Includes defines for the interrupt assignments.
#include "hw_memmap.h"                                                          // Includes the base address of the memories and peripherals.
#include "hw_common_reg.h"                                                      // Includes register offsets.
#include "hw_apps_rcm.h"                                                        // ResetClockManager driver.
#include "prcm.h"                                                               // Peripheral Clock and Reset Control Driver.
#include "rom.h"                        
#include "rom_map.h"                    

#include "LL_prcm.h"
//*****************************************************************************
//                      LOCAL FUNCTION PROTOTYPES                           
//*****************************************************************************

//*****************************************************************************
//                      LOCAL FUNCTION DEFINITIONS                         
//*****************************************************************************
/*!
* @brief Manages Reset & Clock of Peripherals (Board Leds, Gpio, Timer, Spi, I2c, SdCard, Uart).
* @param None.
* @return None.
*/
void
initRcc(void)
{
  // Step 1: Enable and reset Clock for LEDs on the board
  MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
  MAP_PRCMPeripheralReset(PRCM_GPIOA1);
  
  // Step 2: Enable and reset clock for Gpio
  
  // Step 3: Enable and Reset the timer blocks
  MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0, PRCM_RUN_MODE_CLK);                 // for software timing
  MAP_PRCMPeripheralClkEnable(PRCM_TIMERA1, PRCM_RUN_MODE_CLK);                 // for input capture
  MAP_PRCMPeripheralClkEnable(PRCM_TIMERA2, PRCM_RUN_MODE_CLK);                 // for control ir led
  MAP_PRCMPeripheralReset(PRCM_TIMERA0);
  MAP_PRCMPeripheralReset(PRCM_TIMERA1);
  MAP_PRCMPeripheralReset(PRCM_TIMERA2);
  
  // Step 4: Enable and reset SPI blocks
  MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);                    // for communication with thread module
  MAP_PRCMPeripheralReset(PRCM_GSPI);
  
  // Step 5: Enable and reset I2C blocks
  MAP_PRCMPeripheralClkEnable(PRCM_I2CA0, PRCM_RUN_MODE_CLK);                   // for temp&hum sensor
  MAP_PRCMPeripheralReset(PRCM_I2CA0);

  // Step 6: Enable and reset SdCard blocks
  MAP_PRCMPeripheralClkEnable(PRCM_SDHOST, PRCM_RUN_MODE_CLK);                   // for temp&hum sensor
  MAP_PRCMPeripheralReset(PRCM_SDHOST);
  
  // Step 7: Enable and reset UART blocks
  MAP_PRCMPeripheralClkEnable(PRCM_UARTA0, PRCM_RUN_MODE_CLK);                  // for debug interface
  MAP_PRCMPeripheralReset(PRCM_UARTA0); 
  MAP_PRCMPeripheralClkEnable(PRCM_UARTA1, PRCM_RUN_MODE_CLK);                  // for device driver
  MAP_PRCMPeripheralReset(PRCM_UARTA1);  
}