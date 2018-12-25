#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t prod;
pthread_t cons;

sem_t empty;

struct queue
{
	int i;
	struct queue *next; 
};

struct queue *front,*rear;

void* producer()
{
	printf("\nProducer created");
	while(1)
	{
		int l;
		srand(time(0));
		if(front==NULL)
		{
			struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
			temp->next=NULL;
			l=rand()%50+1;
			temp->i=l;
			front=temp;
			rear=temp;
		}
		else
		{
			struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
			temp->next=NULL;
			l=rand()%50+1;
			temp->i=l;
			rear->next=temp;
			rear=temp;
		}
		printf("\nProduced = %d",l);
		sem_post(&empty);
		sleep(1);
	}

}

void* consumer()
{
	printf("\nConsumer created");
	while(1)
	{
		sem_wait(&empty);
		if(front==NULL)
		{
			printf("\nBuffer is empty");
		}
		else if(front->next==NULL)
		{
			struct queue *temp=front;
			front=rear=NULL;
			printf("\nConsumed = %d",temp->i);
			free(temp);
		}
		else
		{
			struct queue *temp=front;
			front=front->next;
			printf("\nConsumed = %d",temp->i);
			free(temp);
		}
		sleep(3);
	}
}

int main(void)
{
	int i,j,k;
	front=rear=NULL;
	sem_init(&empty,0,0);
	pthread_create(&prod,NULL,producer,NULL);
	sleep(2);
	pthread_create(&cons,NULL,consumer,NULL);
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	return 0;
}
