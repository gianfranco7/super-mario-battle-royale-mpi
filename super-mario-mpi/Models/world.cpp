#include "entities.cpp"
#define WORLD_SIZE 100
using namespace std;

class World
{
 //0 Hole, 1 Coin, 2 Little Goomba, 3 Koopa Troopa, 4 Empty, 5 Flag

    int processID;
    Entities world[WORLD_SIZE]; 

    public:

        World()
        {
            world[0].addEntity("Empty");
            world[1].addEntity("Empty");
            world[2].addEntity("Empty");
            world[3].addEntity("Empty");
            world[4].addEntity("Empty");
            world[5].addEntity("Empty");
            world[6].addEntity("Empty");
            world[7].addEntity("Empty");
            world[8].addEntity("Coin");
            world[9].addEntity("Empty");
            world[10].addEntity("Empty");
            world[11].addEntity("Little Goomba");
            world[11].addEntity("Coin");
            world[11].addEntity("Coin");
            world[12].addEntity("Empty");
            world[13].addEntity("Empty");
            world[14].addEntity("Empty");
            world[15].addEntity("Empty");
            world[16].addEntity("Empty");
            world[17].addEntity("Empty");
            world[18].addEntity("Empty");
            world[19].addEntity("Empty");
            world[20].addEntity("Little Goomba");
            world[21].addEntity("Empty");
            world[22].addEntity("Empty");
            world[23].addEntity("Empty");
            world[24].addEntity("Empty");
            world[25].addEntity("Little Goomba");
            world[26].addEntity("Little Goomba");
            world[27].addEntity("Empty");
            world[28].addEntity("Empty");
            world[29].addEntity("Empty");
            world[30].addEntity("Empty");
            world[31].addEntity("Empty");
            world[32].addEntity("Empty");
            world[33].addEntity("Empty");
            world[34].addEntity("Hole");
            world[35].addEntity("Empty");
            world[36].addEntity("Empty");
            world[37].addEntity("Empty");
            world[38].addEntity("Empty");
            world[39].addEntity("Empty");
            world[40].addEntity("Little Goomba");
            world[41].addEntity("Little Goomba");
            world[42].addEntity("Empty");
            world[43].addEntity("Hole");
            world[44].addEntity("Empty");
            world[45].addEntity("Empty");
            world[46].addEntity("Empty");
            world[47].addEntity("Coin");
            world[48].addEntity("Little Goomba");
            world[49].addEntity("Little Goomba");
            world[50].addEntity("Empty");
            world[51].addEntity("Empty");
            world[52].addEntity("Empty");
            world[53].addEntity("Coin");
            world[53].addEntity("Koopa Troopa");
            world[54].addEntity("Coin");
            world[55].addEntity("Empty");
            world[56].addEntity("Coin");
            world[57].addEntity("Little Goomba");
            world[57].addEntity("Little Goomba");
            world[58].addEntity("Empty");
            world[59].addEntity("Empty");
            world[60].addEntity("Empty");
            world[61].addEntity("Empty");
            world[62].addEntity("Little Goomba");
            world[62].addEntity("Little Goomba");
            world[63].addEntity("Empty");
            world[64].addEntity("Little Goomba");
            world[64].addEntity("Little Goomba");
            world[64].addEntity("Coin");
            world[65].addEntity("Coin");
            world[66].addEntity("Empty");
            world[67].addEntity("Empty");
            world[68].addEntity("Empty");
            world[69].addEntity("Empty");
            world[70].addEntity("Empty");
            world[71].addEntity("Empty");
            world[72].addEntity("Empty");
            world[73].addEntity("Empty");
            world[74].addEntity("Empty");
            world[75].addEntity("Empty");
            world[76].addEntity("Empty");
            world[77].addEntity("Hole");
            world[78].addEntity("Empty");
            world[79].addEntity("Empty");
            world[80].addEntity("Empty");
            world[81].addEntity("Empty");
            world[82].addEntity("Empty");
            world[83].addEntity("Empty");
            world[84].addEntity("Empty");
            world[85].addEntity("Coin");
            world[86].addEntity("Empty");
            world[87].addEntity("Little Goomba");
            world[88].addEntity("Little Goomba");
            world[89].addEntity("Empty");
            world[90].addEntity("Empty");
            world[91].addEntity("Empty");
            world[92].addEntity("Empty");
            world[93].addEntity("Empty");
            world[94].addEntity("Empty");
            world[95].addEntity("Empty");
            world[96].addEntity("Empty");
            world[97].addEntity("Empty");
            world[98].addEntity("Empty");
            world[99].addEntity("Flag");
        }

        void printWorld()
        {
            for(int i = 0; i < WORLD_SIZE; i++)
            {
                list<string> entities = world[i].getEntities();
                list<string>::iterator it;
                cout << "Entites on block # " << i << " : ";
                for(it = entities.begin(); it != entities.end(); ++it)
                {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }
};