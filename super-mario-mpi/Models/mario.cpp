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
};
