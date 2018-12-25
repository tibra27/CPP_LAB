#include<stdio.h>
#include<pthread.h>

void * fun()         //function to run when thread is created.
{
	printf("you are in thread:::\n");
}

int main()
{
	pthread_t t1;      //create a thread id
	pthread_create(&t1,NULL,fun,NULL);    //create thread
	printf("you are in main function:::\n");
	pthread_join(t1,NULL);   //for holding the main fun. so that before execution of thred,the main fun. can not be exit.
	return 0;
}
