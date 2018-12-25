#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void qwerty(int key)
{
	printf("\nkey pressed: %d\n",key);
	(void)signal(SIGINT,SIG_DFL);
}
int main()
{
	(void)signal(SIGINT,qwerty);
	pid_t p;
	int c=0;
	while(1)
	{
		printf("process id is %d\n",p);
		printf("sleep time: %d\n",c);
		c++;
		sleep(1);
	}
}
