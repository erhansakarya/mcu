#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// includes for hardware
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"

//includes for util
#include "util.h"

//*****************************************************************************
//
// Static functions
//
//*****************************************************************************

// Features:
// GPIO_SetDirection
// GPIO_GetDirection
// GPIO_SetData
// GPIO_GetData

/*!
* @brief  Get GPIO Direction (Input/Output) of Peripherals
* @param 
*       periph : GPIO_Ax->CONFIG->DIR
*       pin: GpioPinEnum_t bit number in port (0...7)
* @return
*       UtilEnum_t INPUT / OUTPUT
*/
UtilEnum_t GPIO_GetPinDirection(GPIO_Data_t* periph, GpioPinEnum_t pin){
  
}

/*!
* @brief  Set GPIO Direction (Input/Output) of Peripherals
* @param 
*       periph : GPIO_Ax->CONFIG->DIR
*       pin: GpioPinEnum_t bit number in port (0...7)
*       direction : UtilEnum_t INPUT / OUTPUT
* @return
*       0 is true and -1 is false
*/
int8_t GPIO_SetPinDirection(GPIO_Data_t* periph, GpioPinEnum_t pin, UtilEnum_t direction){
  
  switch (direction) {
    case OUTPUT:
      // orlanmis pin degerlerini periph data degeri ile or'la
      // GetPinDirection ile test et
      //return (!PRCM_GetPeriphClkState(periph, mode)) ? 0 : -1;
      break;
    case INPUT:
      // orlanmis pin degerlerini tersle ve periph data degeri ile or'la
      // GetPinDirection ile test et
      //return (!PRCM_GetPeriphClkState(periph, mode)) ? 0 : -1;
      break;
    default:
      // TO-DO: Log error
      return -1;
  }
}