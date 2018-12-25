#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[])
{
    MPI_Init(&argc,&argv);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    float a1=MPI_Wtime();
	printf("start time for process %d is=%f\n\n",world_rank,a1);
	printf("From process %d out of %d,Hello World!\n\n", world_rank,world_size);
	// Finalize the MPI environment.
	float a2=MPI_Wtime();
	printf("end time for process %d is=%f\n\n", world_rank,a2);
    MPI_Finalize();
}

