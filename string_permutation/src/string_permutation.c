/*
 ============================================================================
 Name        : string_permutation.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void string_permutation(char array[]);

int main(void) {
	char array[]="abcd";
	string_permutation(array);
	return 0;
}

void string_permutation(char array[]){
	int size=strlen(array);

	for(int i = 0; i<=size-1;i++){

		char workerarray[size];

		for(int j = 0;j<=size-1;j++){
			workerarray[j] = array[j];
		}


		char temp = workerarray[0];
		workerarray[0] = workerarray[i];
		workerarray[i] = temp;

		printf("%s",workerarray);
		printf("\n");


		for(int j =1; j<=size-1;j++){

			for(int k =j+1; k<=size-1;k++){

				char temp = workerarray[k];
				workerarray[k] = workerarray[j];
				workerarray[j] = temp;

				printf("%s\n",workerarray);
			}

		}
		printf("\n");
	}



}
