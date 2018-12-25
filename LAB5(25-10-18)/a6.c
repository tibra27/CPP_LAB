#include<stdio.h>
#include <mpi.h>
void main (int argc, char *argv[]) 
{
   int r;
   struct {
     double v;
     int r;
   } in, out;
   int rt;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&r);
   in.v=r+1;
   in.r=r;
   rt=7;
   MPI_Reduce(&in, &out, 1, MPI_DOUBLE_INT, MPI_MAXLOC, rt,MPI_COMM_WORLD);
   if(r==rt) printf("PE:%d max=%lf at rank %d\n", r, out.v, out.r);
   MPI_Reduce(&in, &out, 1, MPI_DOUBLE_INT, MPI_MINLOC, rt, MPI_COMM_WORLD);
   if(r==rt) printf("PE:%d min=%lf at rank %d\n", r, out.v, out.r);
   MPI_Finalize();
}


