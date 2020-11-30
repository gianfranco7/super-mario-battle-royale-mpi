#include <iostream>
#include <vector>
#include <map>
#include "../Models/world.cpp"
using namespace std;

class Mario
{
    int id;
    int location;
    int coins;
    bool isActive;
    char strategy;
    World world;

public:
    Mario()
    {
        id = 0;
        location = 0;
        coins = 0;
        isActive = true;
        strategy = getStrategy();
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

    int generateRandomInt(int lowerLimit, int upperLimit)
    {
        srand(time(NULL));
        return (rand() % (upperLimit + 1)) + lowerLimit;
    }

    char getStrategy()
    {
        int choice = generateRandomInt(0, 3);
        switch (choice)
        {
        case 0:
            return 'R';
        case 1:
            return 'L';
        case 2:
            return 'M';
        case 3:
            return 'A';
        }
    }

    list<string> getWorldBlock(int position)
    {
        list<string> entities = world.getBlockElements(position);
        /*list<string>::iterator it;
        cout << "Entites on block # " << position << ": ";
        for (it = entities.begin(); it != entities.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;*/
        return entities;
    }

    multimap<int, string> getEncounterOutcomes(list<string> blockEntities)
    {
        multimap<int, string> outcomes;
        list<string>::iterator it;
        for(it = blockEntities.begin(); it != blockEntities.end(); ++it)
        {   
            string entity = *it;
            if(entity == "Coin")
            {
                int outcome = -1;
                outcome = getCoinEncounterOutcome();
                outcomes.insert(pair <int,string> (outcome, entity));
            }
            if(entity == "Hole")
            {
                int outcome = -1;
                outcome = getHoleEncounterOutcome();
                outcomes.insert(pair <int,string> (outcome, entity));
            }
            if(entity == "Little Goomba")
            {
                int outcome = -1;
                outcome = getLittleGoombaEncounterOutcome();
                outcomes.insert(pair <int,string> (outcome, entity));
            }
            if(entity == "Koopa Troopa")
            {
                int outcome = -1;
                outcome = getKoopaTroopaEncounterOutcome();
                outcomes.insert(pair <int,string> (outcome, entity));
            }
        }
        return outcomes;
    }

    void travelWorld()
    {
        for (int i = 0; i < WORLD_SIZE; ++i)
        {
            if (getWorldBlock(i).empty())
            {
                cout << "World pos. " << location << ": ";
                cout << "Mario #" << id << " is walking ";
                cout << "Coins: " << coins;
                cout << " |";
                cout << endl;
                location++;
            }else
            {
                getEncounterOutcomes(getWorldBlock(i));
            }
        }
    }

    bool calculateProbabilityResult(int probability)
    {
        return (rand() % 100) < probability;
    }

    int calculateEncounterResult(vector<double> probs)
    {
        int randomNumber = generateRandomInt(1, 100), upperLimit = 0;
        for (__SIZE_TYPE__ i = 0; i < probs.size(); ++i)
        {
            upperLimit = upperLimit + (probs[i] * 100);
            if (randomNumber <= upperLimit)
            {
                return i;
            }
        }
        return 0;
    }

    int getCoinEncounterOutcome()
    {
        vector<double>probabilities = {0.5,0.5};
        return calculateEncounterResult(probabilities);
    }

    int getHoleEncounterOutcome()
    {
        vector<double>probabilities = {0.05,0.95};
        return calculateEncounterResult(probabilities);
    }

    int getLittleGoombaEncounterOutcome()
    {
        vector<double> probabilities = {0.05, 0.55, 0.40};
        return calculateEncounterResult(probabilities);
    }

    int getKoopaTroopaEncounterOutcome()
    {
        vector<double> probabilities = {0.10, 0.53, 0.37};
        return calculateEncounterResult(probabilities);
    }
};
