#include <stdint.h>

#include "Board_LED.h"
#include "Board_Buttons.h"

void delay(void){
	uint32_t i = 0;
	
	for(i; i<500000; i++);
}

int main(void){
	uint8_t state = 0;
	
	LED_Initialize();
	Buttons_Initialize();
	
	while(1){
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
