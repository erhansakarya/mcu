#ifndef __HW_PRCM_H__
#define __HW_PRCM_H__

//*****************************************************************************
//
// defines for the PRCM (Power Clock Reset Manager) register offsets.
//
//*****************************************************************************
typedef struct {                // offsets
  uint32_t CAMCLKCFG;           // 0x00
  uint32_t CAMCLKEN;            // 0x04
  uint32_t CAMSWRST;            // 0x08
  uint16_t RESERVED;            // 0x12
  uint32_t MCASPCLKEN;          // 0x14
  uint32_t MCASPSWRST;          // 0x18
  uint16_t SDIOMCLKCFG;         // 0x20
  uint32_t SDIOMCLKEN;          // 0x24
  uint32_t SDIOMSWRST;          // 0x28
  uint32_t APSPICLKCFG;         // 0x2C
  uint32_t APSPICLKEN;          // 0x30
  uint32_t APSPISWRST;          // 0x34
  uint32_t RESERVED_0;          // 0x38
  uint32_t RESERVED_1;          // 0x3C
  uint32_t RESERVED_2;          // 0x40
  uint32_t RESERVED_3;          // 0x44
  uint32_t DMACLKEN;            // 0x48
  uint32_t DMASWRST;            // 0x4C
  uint32_t GPIO0CLKEN;          // 0x50
  uint32_t GPIO0SWRST;          // 0x54
  uint32_t GPIO1CLKEN;          // 0x58
  uint32_t GPIO1SWRST;          // 0x5C
  uint32_t GPIO2CLKEN;          // 0x60
  uint32_t GPIO2SWRST;          // 0x64
  uint32_t GPIO3CLKEN;          // 0x68
  uint32_t GPIO3SWRST;          // 0x6C
  uint32_t GPIO4CLKEN;          // 0x70
  uint32_t GPIO4SWRST;          // 0x74
  uint32_t WDTCLKEN;            // 0x78
  uint32_t WDTSWRST;            // 0x7C
  uint32_t UART0CLKEN;          // 0x80
  uint32_t UART0SWRST;          // 0x84
  uint32_t UART1CLKEN;          // 0x88
  uint32_t UART1SWRST;          // 0x8C
  uint32_t GPT0CLKCFG;          // 0x90
  uint32_t GPT0SWRST;           // 0x94
  uint32_t GPT1CLKEN;           // 0x98
  uint32_t GPT1SWRST;           // 0x9C
  uint32_t GPT2CLKEN;           // 0xA0
  uint32_t GPT2SWRST;           // 0xA4
  uint32_t GPT3CLKEN;           // 0xA8
  uint32_t GPT3SWRST;           // 0xAC
  uint32_t MCASPCLKCFG0;        // 0xB0
  uint32_t MCASPCLKCFG1;        // 0xB4
  uint32_t RESERVED_4;          // 0xB8
  uint32_t RESERVED_5;          // 0xBC
  uint32_t RESERVED_6;          // 0xC0
  uint32_t RESERVED_7;          // 0xC4
  uint32_t RESERVED_8;          // 0xC8
  uint32_t RESERVED_9;          // 0xCC
  uint32_t RESERVED_10;         // 0xD0
  uint32_t RESERVED_11;         // 0xD4
  uint32_t I2CLCKEN;            // 0xD8
  uint32_t I2CSWRST;            // 0xDC
  uint32_t RESERVED_12;         // 0xE0
  uint32_t LPDSREQ;             // 0xE4
  uint32_t RESERVED_13;         // 0xE8
  uint32_t TURBOREQ;            // 0xEC
  uint32_t RESERVED_14;         // 0xF0
  uint32_t RESERVED_15;         // 0xF4
  uint32_t RESERVED_16;         // 0xF8
  uint32_t RESERVED_17;         // 0xFC
  uint32_t RESERVED_18;         // 0x100
  uint32_t RESERVED_19;         // 0x104
  uint32_t DSLPWAKECFG;         // 0x108
  uint32_t DSLPTIMRCFG;         // 0x10C
  uint32_t SLPWAKEEN;           // 0x110
  uint32_t SLPTMRCFG;           // 0x114
  uint32_t WAKENWP;             // 0x118
  uint32_t RESERVED_20;         // 0x11C
  uint32_t RCM_IS;              // 0x120
  uint32_t RCM_IEN;             // 0x124
  
}PRCM_t;

// PRCM Register Structure
#define PRCM  (PRCM_t volatile *GPRCM_BASE)

// enum
typedef enum {
  ENABLE,
  DISABLE,
  RUN_MODE              = (uint32_t)0x01,
  SLEEP_MODE            = (uint32_t)0x100,
  DEEPSLEEP_MODE        = (uint32_t)0x10000,

} PrcmEnum_t;

// functions
extern int8_t PRCM_GetPeriphClkState(uint32_t periph, uint32_t mode);
extern int8_t PRCM_EnDisPeriphClkState(uint32_t periph, const uint8_t enableDisable, uint32_t mode);

#endif // __HW_PRCM_H__
