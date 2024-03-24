#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int rg, val = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rg);
    val = rand();
    MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("proc %d, j'ai recu %d du proc 0\n", rg, val);

    MPI_Finalize(); 
    return 0;
    }