#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    int myid, numprocs, i, j;
    int buffer[10], buffer2[10];
    MPI_Request req, req2;
    MPI_Status status;

    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    j = (myid + 1) % numprocs;
    i = myid - 1;
    if (i < 0)
        i = numprocs - 1;
        
       if(MPI_Issend(buffer2, 10, MPI_INT,j, 123, MPI_COMM_WORLD, &req2)==0)
     {
         printf("Success in Issend()\n");
      }
     if(MPI_Irecv(buffer, 10, MPI_INT,i, 123, MPI_COMM_WORLD, &req)==0)
     {
         printf("Success in Irecv()\n");
      }
      
    MPI_Wait(&req, &status);
    MPI_Wait(&req2, &status);
    MPI_Finalize();
    return 0;
}
