Stack		EQU		0x00000100	;define stack size of 256 bytes, like #define in C
		
			AREA	STACK, NOINIT, READWRITE, ALIGN=3

StackMem	SPACE	Stack		; allocate 256 bytes and assign the address to StackMem, like malloc in C

			AREA	RESET, DATA, READONLY
			EXPORT	__Vectors

__Vectors
			DCD		StackMem + Stack	; allocate 32-bits memory with DCD
			DCD		Reset_Handler
			ALIGN
			
			AREA	withoutStartup, CODE, READONLY, ALIGN=2
			ENTRY
			EXPORT	Reset_Handler

Reset_Handler
			MOV		R5, #0x1234
			MOV		R3,	#0x1234
			ADD		R6,	R3, R5
STOP		B		STOP
			END