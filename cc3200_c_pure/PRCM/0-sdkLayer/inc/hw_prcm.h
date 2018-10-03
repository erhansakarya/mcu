#ifndef __HW_PRCM_H__
#define __HW_PRCM_H__

//*****************************************************************************
//
// defines for the PRCM (Power Clock Reset Manager) register offsets.
//
//*****************************************************************************
#define CAMCLKCFG       0x0
#define CAMCLKEN        0x4
#define CAMSWRST        0x8
#define MCASPCLKEN      0x14
#define MCASPSWRST      0x18
#define SDIOMCLKCFG     0x20
#define SDIOMCLKEN      0x24
#define SDIOMSWRST      0x28
#define APSPICLKCFG     0x2C
#define APSPICLKEN      0x30
#define APSPISWRST      0x34
#define DMACLKEN        0x48
#define DMASWRST        0x4C
#define GPIO0CLKEN      0x50
#define GPIO0SWRST      0x54
#define GPIO1CLKEN      0x58
#define GPIO1SWRST      0x5C
#define GPIO2CLKEN      0x60
#define GPIO2SWRST      0x64
#define GPIO3CLKEN      0x68
#define GPIO3SWRST      0x6C
#define GPIO4CLKEN      0x70
#define GPIO4SWRST      0x74
#define WDTCLKEN        0x78
#define WDTSWRST        0x7C
#define UART0CLKEN      0x80
#define UART0SWRST      0x84
#define UART1CLKEN      0x88
#define UART1SWRST      0x8C
#define GPT0CLKCFG      0x90
#define GPT0SWRST       0x94
#define GPT1CLKEN       0x98
#define GPT1SWRST       0x9C
#define GPT2CLKEN       0xA0
#define GPT2SWRST       0xA4
#define GPT3CLKEN       0xA8
#define GPT3SWRST       0xAC
#define MCASPCLKCFG0    0xB0
#define MCASPCLKCFG1    0xB4
#define I2CLCKEN        0xD8
#define I2CSWRST        0xDC
#define LPDSREQ         0xE4
#define TURBOREQ        0xEC
#define DSLPWAKECFG     0x108
#define DSLPTIMRCFG     0x10C
#define SLPWAKEEN       0x110
#define SLPTMRCFG       0x114
#define WAKENWP         0x118
#define RCM_IS          0x120
#define RCM_IEN         0x124

#endif // __HW_PRCM_H__
