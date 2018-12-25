# include <stdio.h>
# include <pthread.h>
#include<stdlib.h>
int Total=0;
int *s;
pthread_mutex_t flag=PTHREAD_MUTEX_INITIALIZER;
void *sum(void *x)
{
    int *i,c;
    i=(int*)x;
    
    for(c=2;c<=*i;c=c+2)
    {
        pthread_mutex_lock(&flag);
        Total=Total+ s[c-1];
        pthread_mutex_unlock(&flag);
    }
    pthread_exit(NULL);    
}
main()
{
    char name[20];
    int id,ns,i,c;
    pthread_t t;
    printf("Enter name,id,total number of subjects:\n");
    scanf("%s%d%d",name,&id,&ns);
    s=(int *)malloc(sizeof(int)*ns);   
    printf("enter marks in each subject:\n");
    for(i=0;i<ns;i++)
    {
  	scanf("%d",&s[i]);
    } 
    pthread_create(&t,NULL,sum,(void *)&ns);
    for(c=1;c<=ns;c=c+2)
    {
        pthread_mutex_lock(&flag);
        Total=Total+s[c-1];
        pthread_mutex_unlock(&flag);
    }
    pthread_join(t,NULL);
    float p=(Total*100)/(100*ns);
    printf("percentage of student is : %f \n",p);
}


