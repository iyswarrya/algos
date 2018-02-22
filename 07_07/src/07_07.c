/*
 ============================================================================
 Name        : 07_07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void func(int n,int m);
int main(void) {
	int n,m;
	printf("enter upper bound: ");
	scanf("%d",&m);
	printf("enter lower bound: ");
	scanf("%d",&n);
	func(n,m);

	return EXIT_SUCCESS;
}
 void func(int n,int m){
	 printf("%d\n",n);
	 if(n<m)
	 func(n+1,m);

 }
