#include<stdio.h>
#include<pthread.h>

void *fun(void *a)   //the argument must be of type void*
{
	char *b;
	b=(char *)a;
	int i;
	for(i=0;i<100000;i++)
	{
		printf("%s %d\n",b,i);
		sleep(1);  //provide gap 
	}
	return(NULL);
	
}

int main()
{
	pthread_t t1,t2;
	char *m1="thread 1:";
	char *m2="thread 2:";
	pthread_create(&t1,NULL,fun,(void *)m1);   //cast argumnt to void*
	pthread_create(&t2,NULL,fun,(void *)m2);
	printf(" THREAD IS CREATED::YOU ARE IN MAIN FUNCTION\n");
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("WORK IS COMPLETED\n");
	return 0;
}
