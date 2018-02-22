/*
 * macro.c
 *
 *  Created on: Dec 19, 2017
 *      Author: ishu_senthil
 */

#include<stdio.h>

#define div(n) n/2

int main(void) {
	int answer, num=4;
	answer = div(num);
	printf("%d",answer);
	return 0;
}
