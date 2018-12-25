#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
int inp[10][10];
int r,c,s=0,f;
int co=-1;
pthread_mutex_t flag=PTHREAD_MUTEX_INITIALIZER;
void * fun(void *x)         //function to be run when thread is created.
{
	pthread_mutex_lock(&flag);
	int i;
	co++;
	f=0;
	for(i=0;i<c;i++)
	{
		f+=inp[co][i];
	}
	sleep(3);
	s=s+f;
	printf("%d\n",f);
	pthread_mutex_unlock(&flag);
	return NULL;
}
int main()
{
	int x,y;
	printf("enter no. of rows and columns respectively\n");
	scanf("%d%d",&r,&c);
	printf("enter the array elements\n");
	for(x=0;x<r;x++)
	{
		for(y=0;y<c;y++)
		{
			scanf("%d",&inp[x][y]);
		}
	}
	pthread_t t[r];
	for(x=0;x<r;x++)
	{
		pthread_create(&t[x],NULL,&fun,NULL);
	}
	for(x=0;x<r;x++)
	{
		pthread_join(t[x],NULL);
	}
	printf("the sum is::%d\n",s);
	return 0;
}

