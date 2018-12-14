		AREA swap, CODE, READONLY
		ENTRY
		EXPORT __main
		
__main
		LDR	R0,=0xAABBCCDD
		LDR	R1,=0x00112233
		EOR	R0,R0,R1		;EOR is exclusive OR
		EOR	R1,R0,R1
		EOR	R0,R0,R1
Stop	B	Stop
		ALIGN
		END