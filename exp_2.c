#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    double startwtime, endwtime;
    int namelen, numproc, myid;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);

    startwtime = MPI_Wtime();
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Get_processor_name(processor_name, &namelen);
    fprintf(stderr, "Processus %d sur la machine %s parmi %d proc \n", myid, processor_name, numproc);
    if(numproc != 3) fprintf(stderr, "il me faut 3 processus\n");
    endwtime = MPI_Wtime();
    printf("temp sur %d = %f\n", myid, endwtime-startwtime);
    MPI_Finalize();
    
    return 0;
}
