#include <stdio.h>
#include <string.h>

#include "mpi.h"
int main(int argc, char** argv )
{
    //see https://www.mpi-forum.org/docs/mpi-1.1/mpi-11-html/node29.html#Node29
    char message[20];
    int myrank;
    MPI_Status status;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &myrank );

    if (myrank == 0)    /* code for process zero */
    {
        strcpy(message,"Hello, there");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);
        printf("message : %s , processor : %d\n", message, myrank);
    }
    else                /* code for process one */
    {
        MPI_Recv(message, 20, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &status);
        printf("received : %s, processor : %d\n", message, myrank);
    }
    MPI_Finalize();
    return 0;
}
