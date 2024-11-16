#ifndef WORLD_H
#define WORLD_H

#include "robots.h"

using namespace std;
const int WORLDSIZE = 10;

class World {
private:
    Robot* grid[WORLDSIZE][WORLDSIZE];
    
public:
    World();
    ~World();
    
    Robot* getAt(int x, int y);
    void setAt(int x, int y, Robot* object);
    void Display();
    void HitMessage(Robot* obj1, Robot* obj2, int dmg);
    void FightCycle();
    bool CheckGrid();
};

#endif 