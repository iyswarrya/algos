/*
 ============================================================================
 Name        : sorted_array.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sorted(int array[], int n);

int main(void) {
	int array[] = {1,2,3,4};
	int n = sizeof(array)/sizeof(int);
	int cout = sorted(array,n);
	printf("%d",cout);
	return 0;
}

int sorted(int array[], int n){
	if(n ==1 || n == 0){
		return 1;
	}
	else if(array[n-1] < array[n-2]){
		return 0;
	}
	return sorted(array,n-1);

}

