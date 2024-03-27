#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // example array
    int static_array[] = {1, 2, 3, 4};

    // Calculate the size of the local array for each process
    const int local_size = sizeof(static_array) / sizeof(int) / size;

    // Create a local array for each process
    int local_array[local_size];

    // Copy the corresponding elements from the static array to the local array
    for (int i = 0; i < local_size; i++) {
        local_array[i] = static_array[rank * local_size + i];
    }

    int local_sum = 0;
    for (int i = 0; i < local_size; i++) {
        local_sum += local_array[i];
    }

    int global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Array Sum: %d, from %d, with %d workers\n", global_sum, rank, size);
    }

    MPI_Finalize();
    return 0;
}
