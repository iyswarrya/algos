/*
 ============================================================================
 Name        : 13_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readEntireFile(void);
void readUntilMarker(char marker);
void writeToFile(void);
int main(void) {
	readEntireFile();
	readUntilMarker('m');
	return EXIT_SUCCESS;
}
void readEntireFile(void) {
	int ch;
	FILE *fp;
	fp = fopen("/Users/ishu_senthil/Documents/workspace/13_01/src/message", "r");
	ch = getc(fp);
	while (ch != EOF){
		putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);
}

void readUntilMarker(char marker){
	int ch;
		FILE *fp;
		fp = fopen("/Users/ishu_senthil/Documents/workspace/13_01/src/message", "r");
		ch = getc(fp);
		while (ch != marker){
			putchar(ch);
			ch = getc(fp);
		}
		fclose(fp);
}

void writeToFile(void) {
	FILE *fp;
	fp = fopen("/Users/ishu_senthil/Documents/workspace/13_01/src/message","w");
	char name[10] = "ishu";
	fprintf(fp,"%s",name);
	fclose(fp);

}
