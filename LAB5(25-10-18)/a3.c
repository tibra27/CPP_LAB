#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
void main(int argc, char *argv[]) 
{
    int r, i, c;
    float d[100],v[200];
    MPI_Status status;   
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&r);
    if(r==1) 
    {
       for(i=0;i<100;++i) 
       {
			d[i]=i;
	   }
       MPI_Send(d,100,MPI_FLOAT,0,55,MPI_COMM_WORLD); 
    } 
    else 
    {
   	   MPI_Recv(v,200,MPI_FLOAT,MPI_ANY_SOURCE,55,MPI_COMM_WORLD,&status);
       printf("Process:%d Got data from processor %d \n",r,status.MPI_SOURCE);
       MPI_Get_count(&status,MPI_FLOAT,&c);
       printf("Process:%d Got %d elements \n",r,c);
       printf("Process:%d value[5]=%f \n",r,v[5]);
    }
    MPI_Finalize();
 }

