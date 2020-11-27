#include <list>
#include <iostream>

using namespace std;
class Entities
{
    list <string> entities;      
    list <string>::iterator it;

    public:
        Entities()
        {
            it = entities.begin();
        }

        /*~Entities()
        {
            for(it = entities.begin(); it != entities.end(); ++it)
            {
                entities.erase(it);
            }
        }*/

        void addEntity(string entity)
        {
            entities.insert(it,entity);
        }

        list <string> getEntities()
        {
            return entities;
        }

        void removeEntity(string entity)
        {

        }
};