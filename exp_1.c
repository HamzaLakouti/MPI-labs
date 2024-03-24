#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
	int num_process, my_id;

	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	MPI_Comm_size(MPI_COMM_WORLD, &num_process);

	printf("hello am %i out of %i \n", my_id, num_process);

	MPI_Finalize();
	return 0; 
	}
