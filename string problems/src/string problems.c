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
#include <stdbool.h>
#include <string.h>

/*char *string_reverse(char *str){
	int i,len;
	len = strlen(str);

	for(i = 0;i<len/2 ;i++){
		char temp = *(str+i);
 *(str+i) = *(str+len-i-1);
 *(str+len-i-1) = temp;
	}

	return str;
}

void split(char *str){
	char *token;
	char a,b,c;
	a = '-';
	b = '*';
	c = '+';

	token = strtok(str,"-");
	printf("%s%c",string_reverse(token),a);
	token = strtok(0,"*");
	printf("%s%c",string_reverse(token),b);
	token = strtok(0,"+");
	printf("%s%c",string_reverse(token),c);
	printf("%s",strtok(0,"\0"));
	return;
}

int main(void) {
	char str[] = "1+2*3-20";
	string_reverse(str);
	split(str);
	return EXIT_SUCCESS;
}*/

//**********rotating an array *********
/*int * rotate(int * array,int *array1,int k,int n){

	for(int j = k, p=0; j<n, p<n-k; j++, p++){
 *(array1+j) = *(array+p);
	}

	for(int q =0, r=n-k; q < k,r<n; q++,r++){
 *(array1+q) = *(array+r);
	}

	return array1;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(int);
	int *b = (int*)malloc(sizeof(n));
	b = rotate(a,b,7,n);
	for(int j=0;j<n;j++){
		printf("%d\n",*(b+j));
	}
	return 0;
}*/

//******************************************

// ************reverse words in a string**********

/*char *reverse(char *str){
	int size = strlen(str);

	for(int i =0;i<size/2;i++){
		char temp = *(str+i);
 *(str+i) = *(str+size-1-i);
 *(str+size-1-i) = temp;
	}
	return str;
}

void split(char *str){
	char *token;
	token = strtok(str," ");
	while(token != NULL){
		printf("%s%s",reverse(token)," ");
		token = strtok(NULL," ");
	}
}
int main(){
	char a[]="The sky is blue";
	reverse(a);
	//printf("%s\n",a);
	split(a);
	return 0;
}*/

//*****************upper case check**************

/*void capitals(char *str){
	int i,j,k;
	i=k=0;
	j=1;
	int size = strlen(str);

	while(*(str+i) >= 97  && i<=size){
		i++;
		if(i == size){
			printf("true\n");
			return;
		}
	}

	if(*(str)<97)
		while (*(str+j)>=97  && j<=size){
		j++;
		if(j == size){
			printf("true\n");
			return;
		}
	}

	while(*(str+k) < 97  && k<=size){
		k++;
		if(k == size){
			printf("true\n");
			return;
		}
		}
	printf("false\n");
		return;
}


void detectCapitals(char * str){
	bool isCamel = false;
	bool isallupper = false;
	bool isalllower = false;
	bool isCamelX = false;
	bool isallupperX = false;
	bool isalllowerX = false;
	if(*(str) < 97){


		if(*(str+1) > 97){
			isCamelX = true;
			isCamel = true;
		}else{
			isallupperX = true;
			isallupper = true;
		}
	}else{
		isalllower = true;
		isalllowerX = true;
	}
	printf("______________%s____________\n\n",str);
	for(int i=1;i<strlen(str);i++){
		if(isallupperX){
			if(*(str+i) > 97){
				isallupperX=false;
				//printf("incorrect\n");
			}
		}
		if(isalllowerX){
			if(*(str+i) < 97){
				isalllowerX=false;
				//printf("incorrect\n");
			}
		}
		if(isCamelX){
			if(*(str+i) < 97){
				isCamelX=false;
				//printf("incorrect\n");
			}
		}
	}
	if(isallupper && !isallupperX){
		printf("incorrect-isallupper\n");
	}
	if(isCamel && !isCamelX){
		printf("incorrect-isCamel\n");
	}
	if(isalllower && !isalllowerX){
		printf("incorrect-isalllower\n");
	}
}*/

//****************strcat**************

/*const char *concatenation(char *str1, const char *str2){

	return strcat(str1,str2);
}*/

//*******************************

/*void concatenation(char str1[], char str2[]){
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	printf("%d %d", len_str1,len_str2);
	char str[len_str1+len_str2];
	//str1[4] = str2[0];
	for(int i =0; i<len_str1 ;i++){
		str[i] = str1[i];
	}

	for(int j =0; j<len_str2 ;j++){
			str[len_str1 +j] = str2[j];
		}

	printf("%s", str);
}*/

//***********sorting array of strings**************

void sorting(char **string){
	char *temp;
	//temp = (char*)malloc(sizeof(char)*10);
	printf("%s\n",string[1]);
	printf("%d\n",*(*(string+0)+0));
	printf("%c\n", string[1][0]);
	for(int i=0;i<7;i++){
		for(int j =0;j<7-i;j++){
			if(*(*(string+j)+0) > *(*(string+j+1)+0)){
				temp = *(string+j);
				*(string+j) = *(string+j+1);
				*(string+j+1) = temp;
			}
			else if(*(*(string+j)+0) == *(*(string+j+1)+0)){
				printf("%s\n",*(string+j));
				printf("%s\n",*(string+j+1));
				for(int p=1; p<9 ;p++){
					if(*(*(string+j)+p) > *(*(string+j+1)+p)){
						printf("####\n");
						temp = *(string+j);
						*(string+j) = *(string+j+1);
						*(string+j+1) = temp;
						break;
					}
				}
				//break;
			}
		}
	}
	for(int k=0;k<8;k++){
		printf("%s at address %u\n",*(string+k) , string+k);
	}

}

//***************  remove the characters from the first string which are present in second string******

void remove_string(char *str1, char *str2){
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	int count =0;
	printf("%s\n", str1);
	for(int i=0; i<len_str2; i++){
		for(int j=0; j<len_str1; j++){

			if(*(str1+i) == *(str2+j)){
				printf("####");
				count++;
				printf("%d\n", count);
				while(*(str1)){
					printf("####");
					*(str1+j)= *(str1+j+1);
				//*(str1+j) = '\0';
			}
		}
	}
	}

	//printf("%s", str1);
	return;
}

int main(){
	//	capitals("flaG");
	//	capitals("USA");
	//	capitals("america");
	//	capitals("Google");
	/*printf("########################\n");
	detectCapitals("flaG");
	detectCapitals("fLAg");
	detectCapitals("USA");
	detectCapitals("america");
	detectCapitals("Google");*/
	/*char *str = (char*)malloc(sizeof(char));
	concatenation(str,"cat");
	concatenation(str,"dog");
	printf("%s",str);
	//printf("%s",str);*/
	//char *str1[] = {"Abhishek", "Zeroess","Hello","Amit","Bananan","Problem","Ankush","Ahmed"};
	//char *str1[] = {"Abhishek", "Zeroess","Hello","Bananan","Problem"};
	//sorting(str1);
	//char *str2 = (char*)malloc(sizeof(char));
	char *str1 = "abcdef";
	char *str2 = "bdf";
	remove_string(str1,str2);
	return 0;
}