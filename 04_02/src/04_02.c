/*
 ============================================================================
 Name        : 04_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void) {
	char string1[10]="mira";
	char string2[10]="akhilesh" ;

	printf("Length of string1:%d\n",strlen(string1));
	printf("Length of string2:%d\n",strlen(string2));
	printf("result of comparison of two strings:%d\n",strcmp(string2,string1));
	printf("copying string1 to string 2:%s\n",strcpy(string2,string1));
	printf("copying darling to string 2:%s\n",strcpy(string2,"darling"));
}
