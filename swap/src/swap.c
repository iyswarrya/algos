/*
 ============================================================================
 Name        : swap.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr, int n[]);

int main(void) {
		int num[3];
		int *ptr=num;
		printf("enter elements:\n");
		for(int i=0;i<3;i++){
			scanf("%d",&num[i]);
		}
		for(int j=0;j<3;j++){
			printf("the value before swapping are %d\n",num[j]);
				}

		swap(*ptr, num);
		printf("............................\n");
		for(int k=0;k<3;k++){
			printf("the value after swapping are %d\n",num[k]);
				}

	return EXIT_SUCCESS;
}

void swap(int *ptr, int n[]) {
	//ptr = &num;
	int temp;
	temp = *n; // 5 is stored in temp
	*n = *(n+2); // 7 becomes 1 st number
	*(n+2) = *(n+1); // storing 6in 3rd position.
	*(n+1) = temp;
}
