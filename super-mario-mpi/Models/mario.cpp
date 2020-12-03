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
        return entities;
    }

    //gets a multimap of the event outcome <outcome code, entity>
    multimap<int, string> getEncounterOutcomes(list<string> blockEntities)
    {
        multimap<int, string> outcomes;
        list<string>::iterator it;
        for (it = blockEntities.begin(); it != blockEntities.end(); ++it)
        {
            string entity = *it;
            int outcome = -1;
            if (entity == "Coin")
            {
                outcome = getCoinEncounterOutcome();
                outcomes.insert(pair<int, string>(outcome, entity));
            }
            if (entity == "Hole")
            {
                outcome = getHoleEncounterOutcome();
                outcomes.insert(pair<int, string>(outcome, entity));
            }
            if (entity == "Little Goomba")
            {
                outcome = getLittleGoombaEncounterOutcome();
                outcomes.insert(pair<int, string>(outcome, entity));
            }
            if (entity == "Koopa Troopa")
            {
                outcome = getKoopaTroopaEncounterOutcome();
                outcomes.insert(pair<int, string>(outcome, entity));
            }
        }
        return outcomes;
    }

    void setEncounterResults(multimap<int, string> outcomes)
    {
        multimap<int, string>::iterator it;
        for (it = outcomes.begin(); it != outcomes.end(); ++it)
        {
            if (it->second == "Coin")
            {
                switch (it->first)
                {
                case 0:
                    cout << "World pos. " << location << ": ";
                    ++location;
                    cout << "Mario #" << id << " is walking. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                case 1:
                    cout << "World pos. " << location << ": ";
                    ++location;
                    ++coins;
                    cout << "Mario #" << id << " jumped and grabbed a coin. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                }
            }
            if (it->second == "Hole")
            {
                switch (it->first)
                {
                case 0:
                    cout << "World pos. " << location << ": ";
                    isActive = false;
                    cout << "Mario #" << id << " didn't jump and fell to his death. " << endl;
                    break;
                case 1:
                    cout << "World pos. " << location << ": ";
                    ++location;
                    cout << "Mario #" << id << " jumped and kept walking. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                }
            }
            if (it->second == "Little Goomba")
            {
                switch (it->first)
                {
                case 0:
                    isActive = false;
                    cout << "World pos. " << location << ": ";
                    cout << "Mario #" << id << " didn't jump and was killed by a little goomba. " << endl;
                    break;
                case 1:
                    cout << "World pos. " << location << ": ";
                    ++location;
                    cout << "Mario #" << id << " jumped and avoided the little goomba. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                case 2:
                    cout << "World pos. " << location << ": ";
                    world.removeBlockEement(location, "Little Goomba");
                    ++location;
                    cout << "Mario #" << id << " jumped and killed the little goomba. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                }
            }
            if (it->second == "Koopa Troopa")
            {
                switch (it->first)
                {
                case 0:
                    isActive = false;
                    cout << "World pos. " << location << ": ";
                    cout << "Mario #" << id << " didn't jump and was killed by a koopa troopa. " << endl;
                    break;
                case 1:
                    ++location;
                    cout << "World pos. " << location << ": ";
                    cout << "Mario #" << id << " jumped and avoided the koopa troopa. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                case 2:
                    world.removeBlockEement(location, "Koopa Troopa");
                    ++location;
                    cout << "World pos. " << location << ": ";
                    cout << "Mario #" << id << " jumped and killed the koopa troopa. ";
                    cout << "Coins: " << coins;
                    cout << " |";
                    cout << endl;
                    break;
                }
            }
        }
    }

    void travelWorld()
    {
        while ((location != WORLD_SIZE && isActive == true) && location != 99)
        {
            if (getWorldBlock(location).empty())
            {
                cout << "World pos. " << location << ": ";
                cout << "Mario #" << id << " is walking. ";
                cout << "Coins: " << coins;
                cout << " |";
                cout << endl;
                location++;
            }
            else
            {
                setEncounterResults(getEncounterOutcomes(getWorldBlock(location)));
            }
        }
        if (isActive == true)
        {
            cout << "World pos. " << location << ": ";
            cout << "Mario #" << id << " made it to the flag and won the game! Congratulations! ";
            cout << "Total Coins: " << coins;
            cout << " |";
            cout << endl;
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
        vector<double> probabilities = {0.5, 0.5};
        return calculateEncounterResult(probabilities);
    }

    int getHoleEncounterOutcome()
    {
        vector<double> probabilities = {0.05, 0.95};
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
