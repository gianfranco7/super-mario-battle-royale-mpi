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
	int myID, numProcesses, chosen_id;
	int leastCoinsID = 0;
	int mostCoinsID = 0;
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
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
	MPI_Comm_rank(MPI_COMM_WORLD, &myID);
	if (myID == chosen_id)
	{
		Mario chosen_mario(myID, chosen_id, strategy, numProcesses);
		while (chosen_mario.getIsActive())
		{
			int currentCoins = chosen_mario.getCoins();
			chosen_mario.travelWorld();
			chosen_mario.setLocation(0);
			MPI_Reduce(&currentCoins, &leastCoinsID, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
			chosen_mario.setLeastCoinsID(leastCoinsID);
			MPI_Reduce(&currentCoins, &mostCoinsID, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
			chosen_mario.setMostCoinsID(mostCoinsID);
		}
	}
	else
	{
		Mario mario(myID, chosen_id, numProcesses);
		while(mario.getIsActive())
		{
			int currentCoins = mario.getCoins();
			mario.travelWorld();
			mario.setLocation(0);
			MPI_Reduce(&currentCoins, &leastCoinsID, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
			mario.setLeastCoinsID(leastCoinsID);
			MPI_Reduce(&currentCoins, &mostCoinsID, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
			mario.setMostCoinsID(mostCoinsID);
		}
	}
	MPI_Finalize();
	return 0;
}