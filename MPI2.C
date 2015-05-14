//Programa 2
//Salazar Cárdenas Carlos Eduardo

#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv){

	int size, rank;	
	int i;
	char mensaje[42] = "si tuvieramos parque usted no estaria aqui";
	char recepcion[42];

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	
	for(i=0; i<42; i++){
		if(rank == 0)
			MPI_Send(&mensaje[i], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		if(rank == 1)
			MPI_Recv(&recepcion[i], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
	}

	MPI_Finalize();
}