/*
 ============================================================================
 Name        : thread1.c
 Author      : ishu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#define NUM_THREADS 3

void *increment(void *ptr);
void *decrement(void *ptr);
void *multiply_2(void *ptr);

typedef struct math_operation{
	int a,b,c,d,e,f,g,h,i,j,k;
}set_of_integers;

pthread_mutex_t lock_x;

void *printfun1(char* operation, void *ptr){

	set_of_integers *set_of_integer = (set_of_integers *)ptr;
	printf("This is OPERATION: %s\n",operation);
	printf("a: %d - %s\n",set_of_integer->a,operation);
	printf("b: %d - %s\n",set_of_integer->b,operation);
	printf("c: %d - %s\n",set_of_integer->c,operation);
	printf("d: %d - %s\n",set_of_integer->d,operation);
	printf("e: %d - %s\n",set_of_integer->e,operation);
	printf("f: %d - %s\n",set_of_integer->f,operation);
	printf("g: %d - %s\n",set_of_integer->g,operation);
	printf("h: %d - %s\n",set_of_integer->h,operation);
	printf("i: %d - %s\n",set_of_integer->i,operation);
	printf("j: %d - %s\n",set_of_integer->j,operation);
	printf("k: %d - %s\n",set_of_integer->k,operation);
	return NULL;
}

void *increment(void *ptr){
	set_of_integers *thread_data = (set_of_integers *)ptr;
	pthread_mutex_lock(&lock_x);
	(thread_data->a)++;
	(thread_data->b)++;
	(thread_data->c)++;
	(thread_data->d)++;
	(thread_data->e)++;
	(thread_data->f)++;
	(thread_data->g)++;
	(thread_data->h)++;
	(thread_data->i)++;
	(thread_data->j)++;
	(thread_data->k)++;
	printfun1("increment", ptr);
	pthread_mutex_unlock(&lock_x);
	return NULL;
}
void *decrement(void *ptr){
	set_of_integers *thread_data = (set_of_integers *)ptr;
	pthread_mutex_lock(&lock_x);
	(thread_data->a)--;
	(thread_data->b)--;
	(thread_data->c)--;
	(thread_data->d)--;
	(thread_data->e)--;
	(thread_data->f)--;
	(thread_data->g)--;
	(thread_data->h)--;
	(thread_data->i)--;
	(thread_data->j)--;
	(thread_data->k)--;
	printfun1("decrement", ptr);
	pthread_mutex_unlock(&lock_x);
	return NULL;
}
void *multiply_2(void *ptr){
	set_of_integers *thread_data = (set_of_integers *)ptr;
	pthread_mutex_lock(&lock_x);
	(thread_data->a)*=2;
	(thread_data->b)*=2;
	(thread_data->c)*=2;
	(thread_data->d)*=2;
	(thread_data->e)*=2;
	(thread_data->f)*=2;
	(thread_data->g)*=2;
	(thread_data->h)*=2;
	(thread_data->i)*=2;
	(thread_data->j)*=2;
	(thread_data->k)*=2;
	printfun1("multiply_2", ptr);
	pthread_mutex_unlock(&lock_x);
	return NULL;
}

int main(void)
{
	pthread_t thread[NUM_THREADS];
	set_of_integers thread_data = {.a = 0, .b = 0, .c = 0, .d = 0, .e = 0, .f = 0, .g = 0, .h = 0, .i = 0, .k = 0, .j = 0};
	pthread_mutex_init(&lock_x, NULL);

	printfun1("initial",&thread_data);

	if(pthread_create(&thread[0], NULL, increment, &thread_data) < 0){
		printf("thread creation failed\n");
	}else{
		printf("thread created\n");
	}

	if(pthread_create(&thread[2], NULL, multiply_2, &thread_data) < 0){
		printf("thread creation failed");
	}else{
		printf("thread created\n");
	}

	if(pthread_create(&thread[1], NULL, decrement, &thread_data) < 0){
		printf("thread creation failed");
	}else{
		printf("thread created\n");
	}

	for(int i = 0;i<NUM_THREADS; i++){
		pthread_join(thread[i], NULL);
	}
	printf("======================================================\n");
	printfun1("final",&thread_data);
}


