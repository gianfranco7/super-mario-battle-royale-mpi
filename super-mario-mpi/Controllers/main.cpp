#include "../Models/mario.cpp"
#include "mpi.h"
#include <string.h>
bool validate_entry(int chosen_id)
{
	if (chosen_id == 0)
	{
		return false;
	}
	else
		return true;
}

void travelWorld(Mario mario, int chosenID)
{
}

int main(int argc, char *argv[])
{
	int myID, numProcesses, chosenId;
	int leastCoinsID = 0;
	int mostCoinsID = 0;
	char strategy = ' ';
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
	MPI_Comm_rank(MPI_COMM_WORLD, &myID);
	int attackingIDs[numProcesses];
	bool activePlayers[numProcesses];
	if (argc == 3)
	{
		if (validate_entry((size_t)strtoul(argv[1], NULL, 10)))
		{
			chosenId = (size_t)strtoul(argv[1], NULL, 10);
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
	if (myID == chosenId)
	{
		Mario chosen_mario(myID, chosenId, strategy, numProcesses);
		while (chosen_mario.getIsActive() == true && chosen_mario.getLocation() != 99)
		{
			const char *cstr;
			//MPI_Recv (&cstr, 100, MPI_CHAR, 0, 911, MPI_COMM_WORLD, &status);
			int currentCoins = chosen_mario.getCoins();
			if (chosen_mario.getWorldBlock(chosen_mario.getLocation()).empty())
			{
				if (chosen_mario.getID() == chosenId)
				{
					chosen_mario.printWalkingInfo();
					chosen_mario.printInfo();
				}
				chosen_mario.setLocation(chosen_mario.getLocation() + 1);
			}
			else
			{
				chosen_mario.setEncounterResults(chosen_mario.getEncounterOutcomes(chosen_mario.getWorldBlock(chosen_mario.getLocation())));
				if (chosen_mario.getAttack() != " ")
				{
					string sentAttack = chosen_mario.getAttack();
					const char *cstr = sentAttack.c_str();
					int attackingId = chosen_mario.getAttackingId();
					//MPI_Send(cstr, strlen(cstr), MPI_CHAR, attackingId, 55, MPI_COMM_WORLD);
				}
			}
			MPI_Reduce(&currentCoins, &leastCoinsID, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
			MPI_Reduce(&currentCoins, &mostCoinsID, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
			chosen_mario.setLeastCoinsID(leastCoinsID);
			chosen_mario.setMostCoinsID(mostCoinsID);
		}
		if (chosen_mario.getIsActive())
		{
			if (chosen_mario.getID() == chosenId)
			{
				chosen_mario.printFlagInfo();
				chosen_mario.printInfo();
				chosen_mario.setLocation(0);
			}
		}
		else
		{
			cout << "Please select another mario to spectate" << endl;
			cin >> chosenId;
		}
	}
	else
	{
		Mario mario(myID,chosenId, numProcesses);
		while (mario.getIsActive() == true && mario.getLocation() != 99)
		{
			int currentCoins = mario.getCoins();
			if (mario.getWorldBlock(mario.getLocation()).empty())
			{
				mario.setLocation(mario.getLocation() + 1);
			}
			else
			{
				mario.setEncounterResults(mario.getEncounterOutcomes(mario.getWorldBlock(mario.getLocation())));
			}
			MPI_Reduce(&currentCoins, &leastCoinsID, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
			MPI_Reduce(&currentCoins, &mostCoinsID, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
			mario.setLeastCoinsID(leastCoinsID);
			mario.setMostCoinsID(mostCoinsID);
		}
		if (mario.getIsActive())
		{
			mario.setLocation(0);
		}
	}
	MPI_Finalize();
	return 0;
}