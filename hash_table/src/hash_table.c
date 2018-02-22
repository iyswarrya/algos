/*
 ============================================================================
 Name        : hash_table.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct keyValue{
	char * key;
	char * value;
}keyvalue;

typedef struct hash_map{
	int size;
	keyvalue ** valueArray;
}hash_map;


hash_map * create_hashmap(int size){
	hash_map * hashmap = NULL;

	hashmap = malloc(sizeof(hash_map));
	hashmap->size = size;
	hashmap->valueArray = malloc(sizeof(keyvalue)* size);
	for(int i=0;i<size;i++)
	{
		//hashmap->valueArray[i]->key=malloc(sizeof(char*));
		//hashmap->valueArray[i]->value=malloc(sizeof(char*));
		hashmap->valueArray[i]=NULL;

	}


	return hashmap;
}

int hashcode(char *key, int size){
	int hashcode=0;

	for(int i=0;i<size;i++){
		hashcode += (*(key+i))*31*i;
	}

	return hashcode % size;
}

hash_map * insert(char *key,char *value,hash_map * hash_map){
	int position = hashcode(key,hash_map->size);
	printf("key:%s\thashcode:%d\n",key,position);
	if(hash_map->valueArray[position]){
		printf("key value pair cannot be inserted due to collision %d-------%d\n", position,hash_map->valueArray[position]);
		return hash_map;
	}
	keyvalue * key_value;
	key_value = malloc(sizeof(struct keyValue));
	key_value->key = key;
	key_value->value = value;
	hash_map->valueArray[position] = key_value;
	return hash_map;
}

char *find(char *key,hash_map * hash_map){

	int position = hashcode(key,hash_map->size);
	printf("key:%s\thashcode:%d\n",key,position);
	if(hash_map->valueArray[position] == NULL || (hash_map->valueArray[position] != NULL && strcmp(hash_map->valueArray[position]->key,key) != 0)){
		//printf("no key value pair found\n");
		return NULL;
	}
	return hash_map->valueArray[position]->value;

}

int main(void) {
	hash_map * hash_map = NULL;
	int size = 5;
	hash_map = create_hashmap(size);
	for(int j=0;j<size;j++){
		if(hash_map->valueArray[j]){
			printf("position:%d\t",j);
		}
	}
	//printf("%d\n",hashcode("john",size));printf("%d\n",hashcode("senthil",size));printf("%d\n",hashcode("ishu",size));
	insert("john","pendleton_dr",hash_map);
	//printf("%s\t%s\n",(hash_map->valueArray[0])->key, (hash_map->valueArray[0])->value);
	insert("senthil","chennai",hash_map);
	insert("ishu","pondicherry",hash_map);

	//printf("found value: %s\n",find("sam",hash_map));
	printf("************************ FINd*******************\n");
	printf("found value:%s\n",find("sam",hash_map));
	printf("found value:%s\n",find("senthil",hash_map));
	printf("found value:%s\n",find("john",hash_map));
	printf("found value:%s\n",find("ishu",hash_map));

	for(int i=0;i<10;i++)
	{
		if(hash_map->valueArray[i]){
			//free(hash_map->valueArray[i]);
		}

	}
	//free(hash_map);
	return EXIT_SUCCESS;
}
