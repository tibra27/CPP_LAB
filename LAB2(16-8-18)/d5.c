#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
struct EMPLOYEE
{
	char Ename[50];
	char Eid[11];
	char Edesignation[30];
	int sal[5];
};
struct EMPLOYEE *p;
pthread_mutex_t  t1 = PTHREAD_MUTEX_INITIALIZER;
void* fun(void* x)
{
    pthread_mutex_lock(&t1);
    int i= (int)x;
    float hike = (float)(p->sal[i]-p->sal[i-1])/(p->sal[i-1]);
    hike = hike*100;
    pthread_mutex_unlock(&t1);
    return (void* )(int)(hike);
}
int main()
{
 	p=(struct EMPLOYEE *)malloc(sizeof(struct EMPLOYEE));
	printf("Enter name of employee : ");
	scanf("%s",p->Ename);
	printf("\nEnter ID of employee : ");
	scanf("%s",p->Eid);
	printf("\nEnter designation of employee : ");
    	scanf("%s",p->Edesignation);
    	printf("\nEnter salary of the last five years\n");
    	int i;
    	for(i=0;i<5;i++)
    	{
    		scanf("%d",&p->sal[i]);
    	}
    	pthread_t th[4];
    	for(i=1;i<5;i++)
    	{
    		pthread_create(&th[i],NULL,fun,(void*)i);
    	}
    	void* ANS;
    	for(i=1;i<5;i++)
    	{	
    		pthread_join(th[i],&ANS);
    		printf("Hike after %d year is %d percent\n",i,(int)ANS);
    	}
    	return 0;
}
