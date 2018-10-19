//*****************************************************************************
//
// Application Name     - GPIO Onboard Button Led
// Application Overview - SW3 button toggles the red led.
// Application Details  -
//
//*****************************************************************************

// Standard includes
#include <stdio.h>

// Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "interrupt.h"
#include "hw_apps_rcm.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "prcm.h"
#include "gpio.h"
#include "utils.h"

// Common interface includes
#include "gpio_if.h"

#include "pinmux.h"

//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
#if defined(ccs)
extern void (* const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
//*****************************************************************************
//                 GLOBAL VARIABLES -- End
//*****************************************************************************


//*****************************************************************************
//                      LOCAL FUNCTION PROTOTYPES                           
//*****************************************************************************
void LedButtonRoutine();
static void BoardInit(void);

//*****************************************************************************
//                      LOCAL FUNCTION DEFINITIONS                         
//*****************************************************************************

//*****************************************************************************
//
//! Toggling the red led according to the sw3 button.
//!
//! \param None
//!
//! \return None
//
//*****************************************************************************
void LedButtonRoutine()
{
  GPIO_IF_LedOff(MCU_ALL_LED_IND);
  
  while(1)
  {
    
    // read SW3 button
    if(MAP_GPIOPinRead(GPIOA1_BASE, 0x20)){
      MAP_GPIOPinWrite(GPIOA1_BASE, 0x02, ~GPIOPinRead(GPIOA1_BASE, 0x2));      // toggle red led
    }
  }

}
//*****************************************************************************
//
//! Board Initialization & Configuration
//!
//! \param  None
//!
//! \return None
//
//*****************************************************************************
static void
BoardInit(void)
{
/* In case of TI-RTOS vector table is initialize by OS itself */
#ifndef USE_TIRTOS
    // Set vector table base
#if defined(ccs)
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
#endif
#if defined(ewarm)
    MAP_IntVTableBaseSet((unsigned long)&__vector_table);
#endif
#endif
    
    // Enable Processor
    MAP_IntMasterEnable();
    MAP_IntEnable(FAULT_SYSTICK);

    PRCMCC3200MCUInit();
}
//****************************************************************************
//
//! Main function
//!
//! \param none
//! 
//! This function  
//!    1. Invokes the LedButtonRoutine
//!
//! \return None.
//
//****************************************************************************
int
main()
{
    // Initialize Board configurations
    BoardInit();
    
    // Configures GPIOs of buttons/leds
    PinMuxConfig();
    
    // Start the LedButtonRoutine
    LedButtonRoutine();
    return 0;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
