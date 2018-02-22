/*
 ============================================================================
 Name        : stringfindAndReplace.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void string_write(char *str1, char * str2,char *str3) {
     int str1_offset = 0;

     char * str4 = malloc(100);
     while (str1_offset < strlen(str1))
     {
         if (findandreplace(str1,str1_offset, str2, str3, str4) == 0)
             str1_offset += strlen(str2);
         else
             str1_offset++;
     }

     printf("%s\t%s\t%s\t",str1,str2,str3);

}

int findandreplace(char *s1,int str1_offset, char *s2, char *s3, char *s4) {
    if (strstr(s1, s2, strlen(s2)) == 0) {
        strcpy(s4+strlen(s4), s3);
        printf("%s\t%s\t%s\t",s1,s2,s3);
        return 0;
    } else {
    	printf("%s\t%s\t%s\t",s1,s2,s3);
        strncpy(s4+str1_offset, s1, 1);
        return 1;
    }
}

int main(void) {
	string_write("acumanam","cu","pulma"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}