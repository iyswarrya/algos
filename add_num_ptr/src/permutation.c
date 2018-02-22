/*
 ============================================================================
 Name        : add_num_ptr.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char array[3]="ABC";


	/*for(int i=0;i<4;i++){

		printf("%c",array[i]);
	}*/
	int *ptr = array;
    for(int i=0;i<strlen(array);i++) {

    		char temp = *array;
    		*array=*(array+i);
    		*(array+i)=temp;

    	    for(int j=1;j<strlen(array);j++) {}
    	}
	return 0;
}
