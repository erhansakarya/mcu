#include "module.h"

uint8_t initPeripherals(init_e *init){
	// init LED
	// init GPIO
	// init timer interrupt for 1ms
	
	init = INIT_OK/NOT;

	return 0;
}

uint8_t initModule(module *module){
	initPeripherals(module->init);
	module->status = (module.init == INIT_OK) ? (RUN) : (ERROR);

	return 0;
}

uint8_t handleModule(void){
	module_s module = INIT_MODULE;

	initModule(&module);

	for(;;){
		handleButton(&module.mode);
		handleLed(module.mode);
	}
	return 0;
}

int8_t handleButton(modes_e *mode){
	// buton on mu diye bak
	if(readButton()){
		
	}
	// buton on ise 100ms sonra da on mu diye bak
	// buton 3s ve sonrasında da on mu diye bak
	// buton bırakıldığı zaman mod değişim kararı verilecektir.
}

int8_t handleLed(modes_e mode){
	switch(mode){
		case SHORT_MODE:
		case LONG_MODE:
			evaluateLed(mode);
			break;
		default:
			return -1;
			break;
	}
	return 0;
}

int8_t evaluateLed(modes_e mode){
	switch(mode){
		case SHORT_MODE:
			// 2 kere 1sn'lik on-off, 2 kere 2sn'lik on-off
		case LONG_MODE:
			// 4 kere 1sn'lik on-off, 4 kere 2sn'lik on-off
			break;
		default:
			// error logla.
			return -1;
			break;
	}
	return 0;
}