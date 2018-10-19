#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// includes for hardware
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_prcm.h"

//*****************************************************************************
//
// Static functions
//
//*****************************************************************************

/*!
* @brief  Get Clock State(Enable/Disable) of Peripherals
* @param 
*       periph : member of PRCM register struct
*       enableDisable : clock state
*       mode : RUN_MODE, SLEEP_MODE, DEEPSLEEP_MODE
* @return
*       0 is true and -1 is false
*/
int8_t PRCM_GetPeriphClkState(uint32_t periph, uint32_t mode){
  // mode'lari orla ve register ile and'le
  return ((periph &= mode) == mode) ? 0 : -1;

}

/*!
* @brief Enable/Disable Clocks of Peripherals
* @param 
*       periph : member of PRCM register struct
*       enableDisable : clock state
*       mode : RUN_MODE, SLEEP_MODE, DEEPSLEEP_MODE
* @return
*       0 is true and -1 is false
*/
int8_t PRCM_EnDisPeriphClkState(uint32_t periph, const uint8_t enableDisable, uint32_t mode){
  switch (enableDisable) {
    case ENABLE:
      // orlanmis mode degerlerini al ve register degeri ile or'la
      periph |= mode;
      // getState ile test et ve olumlu/olumsuz don
      return (!PRCM_GetPeriphClkState(periph, mode)) ? 0 : -1;
      break;
    case DISABLE:
      // orlanmis mode degerleini al ve tersleyip, register degeri ile and'le
      periph &= ~mode;
      // getState ile test et ve olumlu/olumsuz don
      return (!PRCM_GetPeriphClkState(periph, mode)) ? 0 : -1;
      break;
    default:
      // TO-DO: Log error
      return -1;
  }
  
}

