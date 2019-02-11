#ifndef MODULE_H
#define MODULE_H

typedef enum{
	START,
	RUN,
	ERROR
}status_e;

typedef enum{
	INIT_NOT = 0,
	INIT_OK	 = 1
}init_e;

typedef enum{
	LONG_MODE,
	SHORT_MODE
}modes_e;

typedef struct{
	STimerType buttonTimer;
}button_s;

typedef struct{
	status_e	status;
	init_e 		init;
	modes_e 	mode;
}module_s;

#define INIT_MODULE {			\
					START,		\
					INIT_NOT,	\
					SHORT_MODE	\
					}			\

#endif
