#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t prod;
pthread_t cons;

sem_t notempty,notfull,buf;

int a[10],pos=-1;

void* producer()
{
	printf("\nProducer created");
	while(1)
	{
		int p=rand()%50+1;
		sem_wait(&notfull);
		sem_wait(&buf);
		pos++;			// critical section
		*(a + pos) = p; 
		printf("\nProduced = %d",p);
		sem_post(&buf);
		sem_post(&notempty);
		sleep(1);
	}
}

void* consumer()
{
	printf("\nConsumer created");
	while(1)
	{
		sem_wait(&notempty);
		sem_wait(&buf);
		int c = *(a+pos);
		pos--;
		printf("\nConsumed = %d",c);
		sem_post(&buf);
		sem_post(&notfull);
		sleep(3);
	}
}

int main(void)
{	
	int i,j,k;
	sem_init(&notempty,0,0);
	sem_init(&notfull,0,9);
	sem_init(&buf,0,1);
	pthread_create(&prod,NULL,&producer,NULL);
	sleep(2);
	pthread_create(&cons,NULL,&consumer,NULL);
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	return 0;
}
