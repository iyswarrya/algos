/*
 ============================================================================
 Name        : 12_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
union symbol {
	int number;
	char letter;
};

int main(void) {
	union symbol value;

	value.number = 20;
	value.letter = 'm';
// 20 is replaced by m. If value.number is declared after value.letter,it will replace m.

	union symbol *ptr;
	ptr = &value;
	char myLetter = ptr ->letter;

	printf("letter in value is %c\n",myLetter);
	printf("address of number in value is %d\n",ptr->number);
	return EXIT_SUCCESS;
}
