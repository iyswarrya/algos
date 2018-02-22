/*
 ============================================================================
 Name        : string.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rotation(char *a, char *b,char *str2,int n);

int main(void) {
	char *a ="iyswaryaaa";
	int n = strlen(a);
	char *str2 = (char*)malloc((a+1));
	rotation(a,"aaaiyswary",str2,n);
	return EXIT_SUCCESS;
}

void rotation(char *a, char *b, char *str2,int n){
	for(int k=0;k<n;k++){
		for(int i=0,q=n-k;i<k,q<n;i++,q++){
					*(str2+i) = *(a+q);
				}
		for(int j=k,p=0;j<n,p<n-k;j++,p++){
			*(str2+j) = *(a+p);
		}

			if(strcmp(str2,b) ==0){
			printf("string rotation of str1 from position %d gives str2\n",n-k);
			printf("%s\n",str2);
			return;
			}
		}
	printf("not found");

	}

