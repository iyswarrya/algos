/*
 ============================================================================
 Name        : add_num_ptr.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char array[4]="ABCD";

	printf("elements are:\n");
	/*for(int i=0;i<4;i++){

		printf("%c",array[i]);
	}*/
	int *ptr = array;
    char temp, temp1;

   /* temp = *(array+2);
    *(array+2)= *(array+3);
    *(array+3) = temp;*/
    //printf("%s\n",array);
    for(int i=0;i<4;i++) {

    		printf("%s\n",array);

    	    for(int j=1;j<4;j++) {
    	    	temp = *(array+2);
    	    	*(array+2)= *(array+3);
    	    	*(array+3) = temp;
    	    	printf("%s\n",array);
    	    	for(int k=2;k<4;k++) {
    	    		//printf("%s\n",array);
    	    		temp = *(array+1);
    	    		*(array+1)=*(array+3);
    	    		temp1 = *(array+2);
    	    		*(array+2)=temp;
    	    		*(array+3) = temp1;
    	    		printf("%s\n",array);
    	    		for(int l=3;l<4;l++) {
    	    			temp = *(array+2);
    	    			*(array+2)= *(array+3);
    	    			*(array+3) = temp;
    	    			printf("%s\n",array);
    	    		}

    	    	}
    	    }
    	}
    					/*{
        	    				temp = *(array+1);
        	    				*(array+1)= *(array+2);
        	    				*(array+2) = temp;
        	    			}*/
	return 0;
}
