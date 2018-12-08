#ifndef __RCC_H
#define __RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

extern uint8_t controlAPB1PeriphClk(uint32_t APB1Peripheral, FunctionalState state);
extern uint8_t controlAPB2PeriphClk(uint32_t APB2Peripheral, FunctionalState state);
extern uint8_t controlAHBPeriphClk(uint32_t AHBPeripheral, FunctionalState state);

#ifdef __cplusplus
}
#endif

#endif /* __RCC_H */
