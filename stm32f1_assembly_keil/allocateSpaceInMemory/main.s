	AREA	myCode, CODE, READONLY
	ENTRY
	EXPORT	__main
		
__main
		LDR		R0, =A		; value at A(address), is loaded into register R0
		MOV		R1, #5		; 
		STR		R1,	[R0]	; value at R1, is stored to R0(address)
	
		LDR		R0, =C
		MOV		R1, #4
		STR		R1,	[R0]
	
		LDR		R0, =D
		MOV		R1, #200
		STR		R1,	[R0]
Stop	B		Stop
	

	AREA	myData, DATA, READWRITE
A	SPACE 4	; allocate 4 Bytes in SRAM memory and assign the address to A, A acts like a pointer.
;B	SPACE 4	; B can not use; beacuse it is Branch instruction.
C	SPACE 4
D	SPACE 4
	END