/*
 ============================================================================
 Name        : 13_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readAndWrite(void);
void appendLine(void);
int main(void) {
	readAndWrite();
	appendLine();
	return EXIT_SUCCESS;
}

void readAndWrite(void) {
	int ch;
	FILE *src,*dest;
	src = fopen("/Users/ishu_senthil/Documents/workspace/13_03/src/src","r");
	dest = fopen("/Users/ishu_senthil/Documents/workspace/13_03/src/dest","w");
	ch = getc(src);
	while(ch != EOF){
		putc(ch,dest);
		ch = getc(src);
	}
	fclose(src);
	fclose(dest);
}

void appendLine(void){
	FILE *fp;
	fp=fopen("/Users/ishu_senthil/Documents/workspace/13_03/src/dest","a");
	fprintf(fp,"\n \n im doing good");
	fclose(fp);
}
