#include <stdint.h>

int main(void){
	
	// 0- declarations of pointers:
	// use Ptr
	int *countPtr, count;															// countPtr is pointer, count is integer variable.
	int *xPtr, *yPtr;																	// both of them are pointers.
	int* xxPtr, yyPtr;																// both of them are pointers.
	
	// 1- pointers pointers:
	uint8_t a = 5;
	uint8_t *aPtr = &a;
	uint8_t result = 0;
	
	(&a == aPtr) ? (result = 1) : (result = 0);				// true
	(a == *aPtr) ? (result = 1) : (result = 0);				// true
	uint8_t **ptr_aPtr = &aPtr;												// address of the aPtr, ptr_aPtr is pointer to pointer
	(&*aPtr == *&aPtr) ? (result = 1) : (result = 0);	// true, because & operand has precedence
	
	// 2- constant qualifier with pointers:
	// We can change pointer to point to any other integer variable.
	// But cannot change value of object pointed using pointer ptr.
	const int *pointerToConstant;											// type of ptr is const int*
	int constantVal = 5;
	pointerToConstant = &constantVal;
	//*pointerToConstant = 6;														// error, because pointerToConstant points read-only data.
	int constantVal1 = 6;
	pointerToConstant = &constantVal1;									// no error...
	
	// Constant pointer to integer variable,
	// means we can change value of object pointed by pointer,
	// but cannot change the pointer to point another variable.
	int *const constantPointer = &constantVal;					// type of ptr int* const
	//constantPointer = &constantVal;										// error for first initialization, but why?
	//constantPointer = &constantVal1;									// error
	*constantPointer = 10;															// true
	
	return 0;
}