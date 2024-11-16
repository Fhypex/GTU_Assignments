#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

class Organism{
    friend class World;
    public:
        Organism();
        Organism(World *world, int x,int y);
        ~Organism();
        virtual void breed() = 0;
        virtual void move() = 0;
        virtual int getType() = 0;
        virtual bool starve() = 0;
    protected:
        int x,y;
        bool moved;
        int breedTicks;
        World *world;

};

 const int WORLDSIZE = 20;
    const int initialants = 100;
    const int initialbugs = 5;
    const int doodlestarve = 3;
    const int doodlestarve = 8;

class Doodlebug : public Organism{

    private:
        int life;
        int steps;
    public:
        Doodlebug(){
            life = 3;
            steps = 0;
        }
        int getLife(){
            return life;
        }
        int getSteps(){
            return steps;
        }
        void setLife(int num){
            life = num;
        }
        void eat(){
            life = 3;
        }
        
        int checkLife(){
            if(life == 0){
                return 0;
            }else{
                return 1;
            }
        }
        

};

class Ant : public Organism{

    private:
        int count;
        int steps;
    public:
        Ant(){
            count = 0;
            steps = 0;
        }
        int getCount(){
            return count;
        }
        int getSteps(){
            return steps;
        }
        void setCount(int num){
            count = num;
        }
        
};

class World{
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
    public:
        World();
        ~World();
        Organism* getAt(int x , int y);
        void setAt(int x, int y, Organism *org);
        void Display();
        void SimulateOneStep();
    private:
        Organism* grid[WORLDSIZE][WORLDSIZE];
};

World::World(){

    int i,j;
    for(i = 0; i < 20 ;i++){
        for(j = 0; i < 20 ;i++){
            grid[i][j] = NULL;
        }
    } 
}

World::~World(){

    int i,j;
    for(i = 0; i < 20 ;i++){
        for(j = 0; i < 20 ;i++){
            if(grid[i][j] != NULL) delete(grid[i][j]);
        }
    }
}

void World::setAt(int x,int y, Organism *org){

}

Organism::Organism(){

}

Organism::~Organism(){

}

Organism* World::getAt(int x , int y){

}

void World::Display(){


}

void World::SimulateOneStep(){

}







int main(){

    srand(time(0));
   
    char *array[20][20];
    int x_axis[5];
    int y_axis[5];
  /* int checkIndex[20][20];
    for(int i = 0; i < 20 ;i++){
        for(int j = 0; i < 20 ;i++){
            checkIndex[i][j] = 0;
        }
    } */
    for(int i = 0; i < 5 ; i++){
        x_axis[i] = rand() % 20;
        y_axis[i] = rand() % 20;
        // checkIndex[x_axis[i]][y_axis[i]] = 1;
    }
    for(int i = 0; i < 100; i++){
        
    }

    for(int i = 0; i < 20 ;i++){
        for(int j = 0; i < 20 ;i++){
            *array[i][j] = ' ';
        }
    }
    
    return 0;
}