#include <stdint.h>

#include "Board_LED.h"
#include "Board_Buttons.h"

void delay(void){
	uint32_t i = 0;
	
	for(i; i<500000; i++);
}

void func3(void){
	//void (*func4) (void) = 0x00000000;
	void (*reset) (void) = 0x00000004;		// Address of the reset handler
	void (*delay) (void) = &delay;
	
	//func4();														// NOTE: Go to hardfault handler because this area of memory reserved.
	reset();															// Hardfault handler!
	//delay();
}

void func2(void){
	func3();
}

void func1(void){
	func2();
}

// Constant global variables live in the flash memory and for example its address is 0x0800 0466 in Page 1.
const uint8_t globalConstantArray[] = {0, 1, 2};

void dummyFunc(void){
	uint8_t *pArray = globalConstantArray;
}

uint32_t value = 0;

void readRAM(void){
	uint32_t* ptrRam = (uint32_t*)0x20000000;
	value = *ptrRam;	// value is arranged in memory as 0x16000000 because ARM uses little-endian
	// The bytes are coded in memory in Little Endian format.
}

// this is a const data or read only data stored in the flash memory of the MCU
const char myData[] = "erhan";

#define BASE_ADDRESS_OF_SRAM 0x20000000

void copyFlashToRam(void){
	for(int i = 0; i < sizeof(myData); i++){
		*((uint8_t *) BASE_ADDRESS_OF_SRAM + (sizeof(char) * i)) = myData[i];
	}
}

int main(void){
	uint8_t state = 0;
	
	copyFlashToRam();
	readRAM();
	dummyFunc();
	
	LED_Initialize();
	Buttons_Initialize();
	
	while(1){
		//func1();
		if(Buttons_GetState()){
			state = !state;
			(state) ? LED_On(0): LED_Off(0);
			//delay();
		}
		
		//LED_Off(0);
		//delay();
	}
	
	return 0;
}
