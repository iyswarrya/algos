/*
 * inc.c
 *
 *  Created on: Dec 19, 2017
 *      Author: ishu_senthil
 */

#include <stdio.h>
#include <stdlib.h>

#include "file.h"

int main(void) {
	int num;
	printf("enter num\n");
	scanf("%d",&num);
	printf("%d",square(num));
	return EXIT_SUCCESS;
}

