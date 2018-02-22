/*
 ============================================================================
 Name        : string_sort_position.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char array[9][10] = {"apple","ball","","elephant","frog","","","","giraffe"};
	int size = sizeof(array) / sizeof(char);
	char alphabet;
	printf("enter the first letter:\n");
	scanf("%c",&alphabet);
	for(int i =0; i< size/10 ; i++){
		//if(alphabet == *(*(array+i)+0)){
		if(alphabet == array[i][0]){
		printf("%s is in position %d\n",array[i],i);
	}
}
	return 0;

}
