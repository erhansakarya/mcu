#ifndef __HW_GPIO_H__
#define __HW_GPIO_H__

//*****************************************************************************
//
// defines for the GPIO (General Purpose Input Outputs) register offsets.
//
//*****************************************************************************
typedef struct {        // offsets
  uint32_t DIR;         // 0x400
  uint32_t IS;          // 0x404
  uint32_t IBE;         // 0x408
  uint32_t IEV;         // 0x40C
  uint32_t IM;          // 0x410
  uint32_t RIS;         // 0x414
  uint32_t MIS;         // 0x418
  uint32_t ICR;         // 0x41C
}GPIO_Config_t;

typedef struct {                                                // offsets
  uint32_t DATA;                                                // 0x00
  GPIO_Config_t volatile *CONFIG = (&DATA + (uint32_t)0x400);   // Points to GPIO_Ax->CONFIG register base address
}GPIO_Data_t;

// GPIO Register Structures
#define GPIO_A0  (GPIO_Data_t volatile *GPIOA0_BASE)
#define GPIO_A1  (GPIO_Data_t volatile *GPIOA1_BASE)
#define GPIO_A2  (GPIO_Data_t volatile *GPIOA2_BASE)
#define GPIO_A3  (GPIO_Data_t volatile *GPIOA3_BASE)

// enum
typedef enum {
  PIN_0 = ((uint8_t)0x01),
  PIN_1 = ((uint8_t)0x02),
  PIN_2 = ((uint8_t)0x04),
  PIN_3 = ((uint8_t)0x08),
  PIN_4 = ((uint8_t)0x10),
  PIN_5 = ((uint8_t)0x20),
  PIN_6 = ((uint8_t)0x40),
  PIN_7 = ((uint8_t)0x80)
} GpioPinEnum_t;

// functions

#endif // __HW_GPIO_H__
