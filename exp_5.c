#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int process_rank, size_of_comm;
    int distro_Arr [4] = {1, 2, 3, 4};
    int scattered_data;
    
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size_of_comm);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);
    MPI_Scatter(&distro_Arr, 1, MPI_INT, &scattered_data,1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("process %d has rec %d\n", process_rank, scattered_data);
    
    MPI_Finalize();
    return 0;
    }