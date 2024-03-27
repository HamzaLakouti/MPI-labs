#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ROWS_A 3
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 3

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Matrices
    int A[ROWS_A][COLS_A] = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };
    int B[ROWS_B][COLS_B] = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };
    int C[ROWS_A][COLS_B] = { 
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Scatter rows of first matrix to different processes
    int *subA = (int *)malloc(sizeof(int) * COLS_A);
    MPI_Scatter(A, COLS_A, MPI_INT, subA, COLS_A, MPI_INT, 0, MPI_COMM_WORLD);

    // Broadcast second matrix to all processes
    MPI_Bcast(B, ROWS_B * COLS_B, MPI_INT, 0, MPI_COMM_WORLD);

    // Perform multiplication for assigned row
    int *subC = (int *)malloc(sizeof(int) * COLS_B);
    for (int i = 0; i < COLS_B; i++) {
        subC[i] = 0;
        for (int j = 0; j < COLS_A; j++) {
            subC[i] += subA[j] * B[j][i];
        }
    }

    // Gather results from all processes
    MPI_Gather(subC, COLS_B, MPI_INT, C, COLS_B, MPI_INT, 0, MPI_COMM_WORLD);

    // Print results
    if (rank == 0) {
        printf("C matrix after multiplication:\n");
        for (int i = 0; i < ROWS_A; i++) {
            for (int j = 0; j < COLS_B; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    // Clean up
    free(subA);
    free(subC);

    MPI_Finalize();
    return 0;
}