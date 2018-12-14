REG0	RN	R0
; REG0	EQU	R0; can not use because EQU uses with 32-bit size values, but RN uses only registers
REG1	RN	R1
SUM		RN	R2

		AREA	RN, CODE, READONLY
		ENTRY
		EXPORT	__main
		
__main
		MOV		REG0,	#0x01
		MOV		REG1,	#0x02
		ADD		SUM,	REG0, REG1
Stop	B		Stop
		END