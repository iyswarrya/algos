/*
 ============================================================================
 Name        : palindrome.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//void copy(char *ptr1, char *ptr2);
/*void palindrome_func(char * ptr);
int main(void) {
	char a[] = "madam";
	palindrome_func(a);
	return EXIT_SUCCESS;
}

void palindrome_func(char * ptr){
	int k = strlen(ptr);
	printf("%d\n",k);
	for(int i=0;i<k/2;i++){
		if(*(ptr+i)  != *((ptr+(k-1))-i)){
			printf("not a palindrome\n");
			return;
		}
	}
	printf("palindrome\n");
}*/

/*int main(){

char array1[] = "miras";
printf("sizeof %d\n",sizeof(array1));
char array2[strlen(array1)];
printf("strlen %d\n",strlen(array1));
copy(array1,array2);
printf("%s - %s\n",array1,array2);
return 0;
}

void copy(char *ptr1, char *ptr2){
int k = strlen(ptr1);
printf("%d\n",k);
for(int i =0; i<=k;i++){
 *(ptr2+i) = *(ptr1+i);
 if(*(ptr1+i) == '\0'){
	return;
 	}
 }
}*/

void merge_arrays(int a[],int b[],int a_size,int b_size);
int main(){
	int a[] ={1,2,3,4};
	int b[] ={5,6,7,8};
	int a_size = sizeof(a)/sizeof(int);
	int b_size = sizeof(b)/sizeof(int);
	merge_arrays(a,b,a_size,b_size);
	return 0;
}

void merge_arrays(int a[],int b[],int a_size,int b_size){

         printf("size %d\n",a_size);

         int c_size = (a_size) + (b_size);
         int c[c_size];
         printf("c size %d\n",c_size);
         int i =0, j=0, k=0;

         while(i<= (a_size)-1 && j <= (b_size)-1){
           if(a[i] <= b[j]){
             c[k++] = a[i++];
           }
           else {
             c[k++] = b[j++];
         }
         }

         while(i<= a_size-1){
           c[k++] = a[i++];
         }

         while(j<= b_size-1){
           c[k++] = b[j++];
         }

       for(int p =0; p<c_size; p++){
         printf("%d\n",c[p]);
       }
       }

