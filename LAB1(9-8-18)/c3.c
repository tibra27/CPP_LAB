#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
double *a;
void * fun(void *x)         //function to be run when thread is created.
{
	int i;
	a=(double *)malloc(sizeof(double)*100);
	for(i=0;i<100;i++)
	{	
		 a[i]=(double)pow(i,0.5);
	}
	return((void *)a);
}
int main()
{
	void * b;
	pthread_t t1;      //create a thread id
	pthread_create(&t1,NULL,fun,NULL);    //create thread
	pthread_join(t1,&b);   //for holding the main fun. so that before execution of thred,the main fun. can not be exit.
	int i;
	a=(double *)b;        //returned value by function will store in second argument of pthread_join.
	for(i=0;i<100;i++)
	{
		printf("square root of %d is %lf\n",i,a[i]);
	}
	return 0;
}
