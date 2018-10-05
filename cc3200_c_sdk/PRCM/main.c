/** @file main.c
*
* @brief using&testing of driverLib PRCM functions
*  
* @par
*
*/

// standard includes
#include <stdio.h>

// driverlib includes
#include "hw_types.h"
#include "hw_ints.h"                                                            // NOTE: Is this include required for this module.
#include "hw_memmap.h"
#include "hw_common_reg.h"                                                      // NOTE: Is this include required for this module.
#include "interrupt.h"                                                          // NOTE: Is this include required for this module.
#include "hw_apps_rcm.h"
#include "prcm.h"
#include "rom.h"                                                                // NOTE: Is this include required for this module. Because not using.
#include "rom_map.h"
#include "utils.h"                                                              // NOTE: Is this include required for this module.

// common interface includes
#include "init_if.h" 
//#include "prcm_if.h"
//#include "gpio_if.h"                                                            // NOTE: Is this include required for this module.

// low layer includes
#include "LL_init.h"

//****************************************************************************
//
//! Main function
//!
//! \param none
//! 
//! This function  
//!    1. Invokes the LEDBlinkyTask
//!
//! \return None.
//
//****************************************************************************
int
main()
{
  LL_boardInit();                                                               // Initialize Board configurations
    
  return 0;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
