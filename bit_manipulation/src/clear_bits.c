/*
 ============================================================================
 Name        : clear_bits.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary(int n);
void clear_MSBtoi(int n, int i);
void clear_LSBtoi(int n, int i);
void upperToLower(char ch);
void lowerToUpper(char ch);
void countSetBits(int n);
void logBase2(int n);
void powerOf2(int n);
int rightmostSetBit(int n);
void equalSum_xor(int n);
void swap_odd_even_bits(int n);
void binary_recursive(int n);
int leftrotate_bits(int n,int i);
int rightrotate_bits(int n,int i);
void countBits_AtoB(int a,int b);
void modulo_powerOf2(int n, int d);
void string_reverse(char str[],int start,int end);
int multiply_3Point5(int x);
int add_1(int x);
int odd_even(int x);
int print_KthLSB(int x,int k);

int  main(void){
/*int binary_val = binary(5);
clear_LSBtoi(215,2);
clear_MSBtoi(215,4);
upperToLower('A');
lowerToUpper('a');
countSetBits(11);
logBase2(10);*/
powerOf2(8);
/*equalSum_xor(10);
int rightSetBit = rightmostSetBit(10);
printf("%d\n",binary(rightSetBit));
swap_odd_even_bits(7);
binary_recursive(11);
int left_rotate = binary(leftrotate_bits(17,2));
printf("\nleft_rotate: %d\n",left_rotate);
int right_rotate = binary(rightrotate_bits(17,2));
printf("\nright_rotate: %d\n",right_rotate);
countBits_AtoB(11,6);
modulo_powerOf2(12, 8);
char str[] = "geeks";
string_reverse(str,0,4);
int x = 3;
printf("multiply by 3.5 %d\n",multiply_3Point5(x));
printf("add 1: %d\n",add_1(x));
odd_even(4);
print_KthLSB(x,1);*/
return 0;
}

int binary(int n){
	int remainder =0;
	int binary =0;
	int i=0;
	while(n>0){
		remainder = n%2;
		binary = binary + (remainder * pow(10,i));
		n = n/2;
		i++;

	}

	return binary;
}

void binary_recursive(int n){
	if(n>1){
		binary_recursive(n/2);
	}
	printf("%d",n%2);

}

void clear_LSBtoi(int n, int i){
int mask = ~((1<< i+1)-1);
n = n & mask;
printf("%d\n",n);
return;
}

void clear_MSBtoi(int n, int i){
int mask = ((1<< i)-1);
n = n & mask;
printf("%d\n",n);
return;
}

void upperToLower(char ch){
	int mask = 32;
	ch = ch | mask;
	printf("%c\n",ch);
	return;
}

void lowerToUpper(char ch){
	int mask = 32;
	ch = ch & (~mask);
	printf("%c\n",ch);
	return;
}

void countSetBits(int n){
	int count =0;
	while(n){
		n = n & (n-1);
		count++;
	}
	printf("no.of set bits :%d\n",count);
}

void logBase2(int n){
	int count=0;
	while(n){
		n=n>>1;
		count++;
	}
	printf("log base 2 : %d\n",count);
}

void powerOf2(int n){
	if( (n & (n-1)) == 0){
		printf("power of 2\n");
	}
		else {
			printf("not power of 2\n");
	}
}

int rightmostSetBit(int n){
	int right_setBit = n ^(n &(n-1));

	return right_setBit;
}

void equalSum_xor(int n){
	int unset_bits = 0;
	while(n){
		if((n & 1) ==0){
		unset_bits ++;
		}
		n = n>>1;
	}
	int num_integers = pow(2,unset_bits);
	printf("num_integers: %d\n",num_integers);

}

void swap_odd_even_bits(int n){
	int m = n & 0xAAAAAAAA;
	m = m>>1;
	int k = n & 0x55555555;
	k = k<<1;
	n = m | k;
	n = binary(n);
	printf("Swapped odd even bits : %d\n", n);

}

int leftrotate_bits(int n,int i){
	int a = n<<i;
	int b = n>>(sizeof(int)-i);
	return a|b;
}

int rightrotate_bits(int n,int i){
	int a = n>>i;
	int b = n<<(sizeof(int)-i);
	return a|b;
}

void countBits_AtoB(int a,int b){
	int n = a^b;
	countSetBits(n);
	return;
}

void modulo_powerOf2(int n, int d){
	int mod = n & (d-1);
	printf("%d\n",binary(mod));
	return;
}

void string_reverse(char str[],int start,int end){
	while(start < end){
	str[start] = str[start] ^ str[end];
	str[end] = str[end] ^ str[start];
	str[start] = str[start] ^ str[end];
	start++;
	end--;
	}
	printf("%s\n",str);
	return;
}

int multiply_3Point5(int x){
	return ((x<<1) + x + (x>>1));
}

int add_1(int x){
	return x = -(~x);
}

int odd_even(int x){
	if(x%2 == 0){
		return printf("even\n");
	}
	else return printf("odd\n");
}

int print_KthLSB(int x,int k){
	int a = 1<< (k-1);
	if((x & a) == 1 ){
		printf("kth LSB is 1\n");
	}
	else printf("kth LSB is 0\n");
	return 0;
}

