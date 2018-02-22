/*
 ============================================================================
 Name        : decimal.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int n;
	//printf("enter n\n");
	//scanf("%d",&n);

	int k,j;
	//k= negate(-4);
	//printf("negated number is %d\n",k);
	n=binary(29);
	//printf("negated binary is %d\n",n);
	k=unset(n,2);
	printf("negated binary is %d\n",k);
	j=binary(k);
	printf("negated binary is %d\n",j);

}

int negate(int n){
	return n>>2;
}

int binary(int n){
	int binary=0;
		int remainder = 0;
		int i = 0;
		while(n > 0){
			remainder = n%2;
			binary=binary+(remainder*pow(10,i));
			n = n/2;
			i++;
		}
		printf("%d\n",binary);
		return binary;
}

int unset(int n, int i){
	int j;
	j= n &(1<<(i+1));
	return j;
}
