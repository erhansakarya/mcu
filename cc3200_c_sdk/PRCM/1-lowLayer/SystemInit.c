/** @file SystemInit.c
*
* @brief
* This module configures the board
*
* @par
*
*/

// Standard includes
#include <stdio.h>

// Driverlib includes
#include "hw_types.h"                   // Includes data types.
#include "hw_ints.h"                    // Includes defines for the interrupt assignments.
#include "hw_memmap.h"                  // Includes the base address of the memories and peripherals.
#include "hw_common_reg.h"              // Includes register offsets.
#include "hw_apps_rcm.h"                // ResetClockManager driver.
#include "prcm.h"                       // Peripheral Clock and Reset Control Driver.
#include "rom.h"                        
#include "rom_map.h"                    

#include "LL_systemInit.h"

//*****************************************************************************
//                      LOCAL FUNCTION PROTOTYPES                           
//*****************************************************************************

//*****************************************************************************
//                      LOCAL FUNCTION DEFINITIONS                         
//*****************************************************************************
/*!
* @brief Board Initialization & Configuration.
* @param None.
* @return None.
*/
void
SystemInit(void)
{
/* In case of TI-RTOS vector table is initialize by OS itself */
#ifndef USE_TIRTOS
    //
    // Set vector table base
    //
#if defined(ccs)
    MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
#endif
#if defined(ewarm)
    MAP_IntVTableBaseSet((unsigned long)&__vector_table);
#endif
#endif
    
    //
    // Enable Processor
    //
    MAP_IntMasterEnable();              // Allows the processor to respond to interrupts.
    MAP_IntEnable(FAULT_SYSTICK);       // Enables the SysTick interrupts.

    PRCMCC3200MCUInit();                // MCU Initialization Routine.
}