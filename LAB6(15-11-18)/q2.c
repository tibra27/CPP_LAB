#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
struct mystruct{
    int sendarray[4];
    int a;
    char array2[4];
};
typedef struct mystruct struct_t;
int main (int argc, char ** argv)
{
    int rank, size;
    struct_t fd;
    struct_t recv;
    int i, j;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    for (i=0;i<4;i++)
    {
        fd.sendarray[i] = 0;
        fd.array2[i] = 0;
        recv.sendarray[i] =999;
        recv.array2[i]    = 99;
    }
    recv.a =999;
    fd.sendarray[rank] = rank*10;
    fd.array2[rank]    = (char)(rank*20);
    fd.a = rank;
    printf("rank : %d, fd.sendarray[%d] : %d\n", rank, rank, fd.sendarray[rank]);
    // gather data from all now.. send the int:
    MPI_Allgather (&(fd.sendarray[rank]), 1, MPI_INT,  recv.sendarray, 1, MPI_INT,  MPI_COMM_WORLD);
    // then the char
    MPI_Allgather (&(fd.array2[rank]),    1, MPI_CHAR, recv.array2,    1, MPI_CHAR, MPI_COMM_WORLD);

    // check if correct data has been received
    if (rank == 0) {
        printf("Received:\n");
        printf("---\n");
        printf("int array:  ");
        for (j=0; j<4; j++) printf("%3d ", recv.sendarray[j]);
        printf("\nchar array: ");
        for (j=0; j<4; j++) printf("%3d ", (int)(recv.array2[j]));
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
