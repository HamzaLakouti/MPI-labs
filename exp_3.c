#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int process_rank, size_cluster, message_item;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size_cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);
    if(process_rank==0){
        message_item = 420;
        MPI_Send(&message_item, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Message : %d\n", message_item);
    }
    else if(process_rank == 1){
        MPI_Recv(&message_item, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Received : %d\n", message_item);
    }

    MPI_Finalize();

    return 0;
}
