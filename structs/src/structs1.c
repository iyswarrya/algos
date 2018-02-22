/*
 ============================================================================
 Name        : dictionary.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : trie.c
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

typedef struct keyvalue{
	char * key;
	char * value;
} key_value;

void work_with_single_struct(key_value * kv){
	kv->key="hello111";
	kv->value="senthil2222";
	return;
}

void work_with_struct_array(key_value kv[]){
	for(int i=0;i<5;i++){
		printf("%s\n",kv[i].key);
		printf("%s\n",kv[i].value);
	}
	printf("-----------&&&&&&&&&&&&--------------\n");
	for(int i=0;i<5;i++){
		char * t1 = "hello11111111111111331123123";
		kv[i].key = t1;
		kv[i].value = "senthil0000000000000";
	}
}

void work_with_struct_array_by_ref(key_value * kv){
	printf("-----------%%%%%%%%%%%%%%%%--------------\n");
	for(int i=0;i<5;i++){
		printf("%s\n",(kv+i)->key);
		printf("%s\n",(kv+i)->value);
	}
	printf("-----------000000000000000--------------\n");
	for(int i=0;i<5;i++){
		(kv+i)->key = "hello56687687e23847947";
		(kv+i)->value = "senthil21389740924912734";
	}
}


void filehandle(){
	static const char filename[] = "file.txt";
	FILE *file = fopen ( filename, "r" );
	int ch,lines=0;
	do
	{
		ch = fgetc(file);
		if (ch == '\n')
			lines++;
	} while (ch != EOF);

	rewind(file);

	char *contents[lines];
	int i = 0;
	size_t len = 0;
	for(i = 0; i < lines; i++)
	{
		contents[i] = NULL;
		len = 0;
		getline(&contents[i], &len, file);
	}
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	for(i = 0; i < lines; i++)
	{
		char *ch;
		ch = strtok(contents[i], "\t");
		while (ch != NULL) {
			printf("hello: %s\n", ch);
			ch = strtok(NULL, "\n");
		}
	}
	fclose(file);
}


int main(void){
	key_value * kv;
	kv = (key_value * )malloc(sizeof(key_value));
	kv->key="hello";
	kv->value="senthil";

	printf("%s\n",kv->key);
	printf("%s\n",kv->value);

	key_value  kv1;

	work_with_single_struct(&kv1);


	printf("%s\n",kv1.key);
	printf("%s\n",kv1.value);


	key_value kv_array[5];
	for(int i=0;i<5;i++){
		//kv_array[i] = (key_value * )malloc(sizeof(key_value));
		kv_array[i].key="hello22222";
		kv_array[i].value="senthil33333";
	}
	for(int i=0;i<5;i++){
		printf("%s\n",kv_array[i].key);
		printf("%s\n",kv_array[i].value);
	}
	printf("---------------------------------------\n");
	work_with_struct_array(&kv_array);
	printf("--------=======================--------------\n");
	for(int i=0;i<5;i++){
		printf("%s\n",kv_array[i].key);
		printf("%s\n",kv_array[i].value);
	}

	work_with_struct_array_by_ref(&kv_array);
	printf("--------289472309523-08385023--------------\n");
	for(int i=0;i<5;i++){
		printf("%s\n",kv_array[i].key);
		printf("%s\n",kv_array[i].value);
	}

	filehandle();
}

