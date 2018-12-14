
		AREA 	startupFileProject, CODE, READONLY
		ENTRY										; Points the execution start
		EXPORT	__main								; makes accesible main routine by other modules
			
__main
		MOV		R5, #0x1234
		MOV		R3,	#0x1234
		ADD		R6,	R3, R5
STOP	B		STOP
		END