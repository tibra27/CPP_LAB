#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) 
{
				int r;
				int b;
				const int rt=0;
				MPI_Init(&argc, &argv);
				MPI_Comm_rank(MPI_COMM_WORLD, &r);
				if(r == rt) {
				   b = 777;
				}
				printf("[%d]: Before Bcast, buf is %d\n", r, b);
				MPI_Bcast(&b, 1, MPI_INT, rt, MPI_COMM_WORLD);
				printf("[%d]: After Bcast, buf is %d\n", r, b);
				MPI_Finalize();
				return 0;
}

