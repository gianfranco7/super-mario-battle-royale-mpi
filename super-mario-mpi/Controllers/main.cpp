#include "../Models/mario.cpp"
#include "mpi.h"

bool validate_entry(int chosen_id)
{
	if (chosen_id == 0)
	{
		return false;
	}
	else
		return true;
}

int main(int argc, char *argv[])
{
	int my_id, num_processes, chosen_id;
	char strategy;
	if (argc == 3)
	{
		if (validate_entry((size_t)strtoul(argv[1], NULL, 10)))
		{
			chosen_id = (size_t)strtoul(argv[1], NULL, 10);
			strategy = *argv[2];
		}
		else
		{
			cout << "Strategy must be R L A or M, id cannot be 0" << endl;
			return 1;
		}
	}
	else
	{
		cout << "Invalid number of parameters" << endl;
		return 2;
	}
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	if (my_id == chosen_id)
	{
		Mario chosen_mario(my_id, chosen_id, strategy);
		chosen_mario.travelWorld();
	}
	else
	{
		Mario mario(my_id, chosen_id);
		mario.travelWorld();
	}
	MPI_Finalize();
	return 0;
}
