#include "../Models/mario.cpp"
#include "mpi.h"
int main(int argc, char *argv[])
{
	int my_id, num_processes, chosen_id;
	if (argc >= 2)
	{
		chosen_id = (size_t)strtoul(argv[1], NULL, 10);
	}
	else
	{
		cout << "Invalid number of parameters" << endl;
		return 1;
	}
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	Mario mario(my_id,chosen_id);
	mario.travelWorld();
	MPI_Finalize();
	return 0;
}
