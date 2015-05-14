//Programa 4
//Salazar Cárdenas Carlos Eduardo

#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv){

	int size, rank, id, vecino;
	int grupos, input = 0, output;	

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	
	grupos = size % 2;
	id = rank % 2;

	if(rank == 0){
		vecino = rank - 1;
		output = 1;
	}else{
		vecino = rank + 1;
		output = 2;
	}

	if(grupos != 0){
		MPI_Send_recv(&output, 1, MPI_INT, vecino, 0, &input, 1, MPI_INT, vecino, 1, MPI_COMM_WORLD, &status);
	}

	MPI_Finalize();
}