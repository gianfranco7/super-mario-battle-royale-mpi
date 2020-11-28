#include <iostream>
#include "../Models/world.cpp"
using namespace std;

class Mario
{
    int location;
    int coins;
    bool isActive;

public:
    Mario()
    {
        location = 0;
        coins = 0;
        isActive = false;
    }

    int getLocation()
    {
        return location;
    }

    int getCoins()
    {
        return coins;
    }

    bool getIsActive()
    {
        return isActive;
    }

    void setIsActive(bool active)
    {
        isActive = active;
    }

    void addCoin()
    {
        ++coins;
    }

    void entityEncounter(string entity)
    {
    }

    void travelWorld()
    {
        for (int i = 0; i < 100; ++i)
        {
            cout << "My current location in world 1:1 is: " << location << endl;
            ++location;
        }
    }

    bool calculateProbabilityResult(int probability)
    {
        return (rand() % 100) < probability;
    }

    int calculateEnemyEncounterResult(int lower, int middle, int upper)
    {
        int result = 0;
        int randomNumber = rand() % (lower + middle + upper);
        randomNumber -= lower;

        if (randomNumber < lower)
        {
            result = 0;
        }

        randomNumber -= middle;
        if (randomNumber < middle)
        {
            result = 1;
        }
        randomNumber -= upper;
        if (randomNumber < upper)
        {
            result = 2;
        }
        return result;
    }

    void coinEncounter(Mario mario, World world)
    {
        if (calculateProbabilityResult(50))
        {
            mario.addCoin();
        }
    }

    void holeEncounter(Mario mario, World world)
    {
        if (calculateProbabilityResult(5))
        {
            mario.setIsActive(false);
        }
        else
        {
            //Mario salta y pasa (Probabilidad 0.95). Esta acción no tienen ningún efecto.
            //Mario se mueve una posicion despues del hueco
        }
    }

    void littleGoombaEncounter(Mario mario, World world)
    {
        int result = calculateEnemyEncounterResult(5, 55, 40);
    }

    void koopaTroopaEncounter(Mario mario, World world)
    {
        int result = calculateEnemyEncounterResult(10, 53, 37);
    }
};
