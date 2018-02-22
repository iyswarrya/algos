/*
 ============================================================================
 Name        : goto.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

void checkEvenOrNot(int num)
{
    if (num % 2 == 0)
        goto even; // jump to even
    else
        goto odd; // jump to odd

even:
    printf(" is evenn");
    return; // return if even
odd:
printf(" is odd");
}

// Driver program to test above function
int main()
{
    int num = 26;
    checkEvenOrNot(num);
    return 0;
}
