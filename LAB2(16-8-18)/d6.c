#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
int p[10000];
int f[10000];
int n,c;
pthread_mutex_t t1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t t2 = PTHREAD_MUTEX_INITIALIZER;
void* funprime()
{
	int i,j,fact;
	pthread_mutex_lock(&t1);
	c=0;
	for(i=1; i<=n; i++)
    	{
        	fact=0;
        	for(j=1; j<=n; j++)
        	{
            		if(i%j==0)
                	fact++;
        	}
        	if(fact==2)
        	{
        		p[c]=i;
            		c++;
            	}
        }
    	pthread_mutex_unlock(&t1);
}
void* funfib()
{
	pthread_mutex_lock(&t2);
	f[0]=0;
	f[1]=1;
	int i;
	for(i=2;i<n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	pthread_mutex_unlock(&t2);
}
int main()
{
    pthread_t th1,th2;
    printf("enter value of n\n");
    scanf("%d",&n);
    pthread_create(&th1,NULL,funprime,NULL);
    pthread_create(&th2,NULL,funfib,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    int i;
    printf("Fibonacci series\n");
    for(i=0;i<n;i++)
    {
    	printf("%d ",f[i]);
    }
    printf("\nPrime Number Series\n");
    for(i=0;i<c;i++)
    {
    	printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}
