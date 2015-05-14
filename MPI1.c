//Programa 1
//Salazar Cárdenas Carlos Eduardo

#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv){

	int size, rank;
	int mensaje = 0;
	int grupo, id;

	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	grupo = size / 2;
	
	if(rank => grupo){
		id = 0;
		mensaje = 1;
		vecino = rank+ grupo;
	}else{
		id = 1;
		vecino = rank - grupo;
	}
	
	if(id == 0)
		MPI_Send(&mensaje, 1, MPI_INT, vecino, 0, MPI_COMM_WORLD);
	if(id == 1)
		MPI_Recv(&mensaje, 1, MPI_INT, vecino, 0, MPI_COMM_WORLD, &status);

	MPI_Finalize();
}