#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int WORLDSIZE = 10;
/*
Function to check the legal moves
this function makes us stay in the boundary of the world
*/

bool checkLegal(int x,int y,int move){      
    
                            switch(move){
                                case 1:
                                    y++;
                                    if(y >= WORLDSIZE){
                                       return false;
                                    }                                 
                                break;
                                case 2:
                                    y--;
                                    if(y < 0){                                       
                                        return false;
                                    }                                
                                break;
                                case 3:
                                    x++;
                                    if(x >= WORLDSIZE){
                                        return false;
                                    }                                
                                break;
                                case 4:
                                    x--;
                                    if(x < 0){
                                        return false;                                       
                                    }
                                break;
                            }
    return true;                        
}

/*
all definitons of the class Robot
other classes are deriven out of this class
*/

class Robot {
    private:    // private values that are common in robot types
        int hp;
        int strength;
        string name;
    public:     // moved common in robot types
        int moved;
    Robot(){    // default constructor
        moved = 0;
        hp = 1;
        strength = 1;
        name = "default";
    }
    Robot(int newHP, int newStrength, string newName){  // parameter constructor
        moved = 0;
        hp = newHP;
        strength = newStrength;
        name = newName;

    }
    /*
    setters and getters defined
    */
    void setHP(int num){
        hp = num;
    }
    void setStrength(int num){
        strength = num;
    }
    int getStrength(){
        return strength;
    }
    int getHP(){
        if (this == nullptr) {
            cout << "ERROR";    // debug purpose
        return hp;
        }
        return hp;
    }
    string getName() {
    if (this == nullptr) {
        return "Null Robot";    // debug purpose
    } else {
        return name;
    }
}
    void setName(string newName){
        name = newName;
    }
    void takeDamage(int damage){
        hp -= damage;
    }
    // virtual functions to take form deriven classes
    virtual int getDamage() = 0;
    virtual int getType1() = 0;
    
};

class bulldozer : public Robot{

    private:
        int type1;  // type1 variable for class to set on construction
    public:

    bulldozer(){    // default constructor
        type1 = 3;
        setStrength(50);
        setHP(200);
    }
    bulldozer(string newName){  // parameter constructor
        type1 = 3;
        setHP(200);
        setStrength(50);
        setName(newName);
    }

    int getType1() override {   
        return type1;
    }
    int getDamage() override {
        int dmg = rand() % getStrength() + 1;
        cout << getName() << " attacks for " << dmg << " points!" << endl;
        return dmg;
    }
};

class roomba : public Robot{

    private:
        int type1;
    public:

    roomba(){               // default constructor
        type1 = 2;
        setHP(10);
        setStrength(3);
    }
    roomba(string newName){ // parameter constructor
        type1 = 2;
        setHP(10);
        setStrength(3);
        setName(newName);
    }

    int getType1() override {
        return type1;
    }
    int getDamage() override {
        int dmg1 = rand() % getStrength() + 1;
        int dmg2 = rand() % getStrength() + 1;
        cout << getName() << " attacks for " << dmg1 + dmg2 << " points!" << endl;
        return dmg1 + dmg2;
    }
};

class kamikaze : public Robot{

    private:
        int type1;
    public:

    kamikaze(){                 // default constructor
        type1 = 4;
        setHP(10);
    }
    kamikaze(string newName){// parameter constructor
        type1 = 4;
        setHP(10);
        setName(newName);
    }

    int getType1() override {
        return type1;
    }
    int getDamage() override {
        cout << getName() << " attacks for " << getHP() << " points!" << endl;
        int dmg = getHP();
        takeDamage(getHP());
        return dmg;
    }
};

class humanic : public Robot{

    private:
        int type1;
    public:

    humanic(){
        type1 = -1;
    }

    virtual int getType1() = 0;
    virtual int getDamage() = 0;
};

class optimusprime : public humanic{

    private:
        int type1;
    public:

        optimusprime(){                     // default constructor
            type1 = 0;
            setHP(100);
            setStrength(100);
        }
        optimusprime(string newName){       // parameter constructor
            type1 = 0;
            setHP(100);
            setStrength(100);
            setName(newName);
        }
        int getType1() override {
            return type1;
        }
        int getDamage(){
            int rand1 = rand() % 20;
            int rand2 = rand() % getStrength() + 1;
            int rand3 = rand() % 10;
            
            if(rand3 == 0){
                rand2 += 50;
            }
            if(rand1 < 3){
                cout << getName() << " attacks for " << rand2 * 2 << " points!" << endl;
                return rand2 * 2;
            }else{
                 cout << getName() << " attacks for " << rand2 << " points!" << endl;
                return rand2;
            }
        }
};

class robocop : public humanic{

    private:
        int type1;
    public:

        robocop(){                      // default constructor
            type1 = 1;
            setHP(40);
            setStrength(30);
        }
        robocop(string newName){        // parameter constructor
            type1 = 1;
            setHP(40);
            setStrength(30);
            setName(newName);
        }

        int getType1() override {
            return type1;
        }
        int getDamage(){
            int rand1 = rand() % 10;
            int rand2 = rand() % getStrength() + 1;
            if(rand1 == 0){
                rand2 += 50;
            }
            cout << getName() << " attacks for " << rand2 << " points!" << endl;
            return rand2;           
        }
};
/*
========================================

World class is friend of all the classes it can reach to friend classes and we make every move
on world class object we set the pointers and simulate the fight
========================================
*/
class World{
friend class Robot; 
friend class optimusprime;
friend class bulldozer;
friend class kamikaze;
friend class roomba;
friend class humanic;
friend class robocop;
private:
    Robot* grid[WORLDSIZE][WORLDSIZE];                  // grid essential for animation

public:
    World(){                    // default constructor

        int i,j;
        for (i = 0 ; i < WORLDSIZE; i++){        
            for (j = 0 ; j < WORLDSIZE; j++){
                grid[i][j]=NULL;
            }
        }
    }
    ~World(){                   // parameter constructor

        int i,j;
        for(i = 0; i < WORLDSIZE ;i++){
            for(j = 0; j < WORLDSIZE ;j++){
                if(grid[i][j] != NULL) delete(grid[i][j]);
            }
        }
    }

    Robot* getAt(int x, int y){         // getter 

        if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
            return grid[x][y];
        }
        return NULL;
    }

    void setAt(int x, int y, Robot *object){        // setter

        if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)){   
            grid[x][y] = object;
        }

    }
    // debug purpose display function to see the grid
    void Display(){

        int i,j;
        cout << endl << endl;
        for (j = 0; j < WORLDSIZE; j++){
        
            for (i = 0; i < WORLDSIZE; i++){
            
                if (grid[i][j]==NULL)
                cout << "O ";
                else cout << "X ";  // if the grid cell is occupied bby a robot we print X
            }
        cout << endl;
        }
    }

    void HitMessage(Robot* obj1 , Robot* obj2, int dmg){
        // basic hit message
        cout << obj1->getName() << " " << obj1->getHP() << " hits " << obj2->getName() << " " << obj2->getHP() << " with " << dmg << endl;
    }
/*
=========================================================

FightCycle is the function i simulate each loop of the world
the function allows robots to move if the cell it wants to move is empty
otherwise they start fighting and the winner takes the place of the loser
if the robot started the fight dies other robot stays in the same position
unfortunately kamikaze robots caused a problem dying on impact i couldnt fix it

=========================================================
*/

    void FightCycle(){
        int i,j;
        int move;
        int dmg;
        int x;
        int y;
        int j_increment;
        int i_increment;
        for(i = 0; i < WORLDSIZE ;i++){     // loop nest
    
            for(j = 0; j < WORLDSIZE ;j++){

                if(grid[i][j] != NULL){
                    
                    if(grid[i][j]->moved == 0){     // if the robot hasnt moved

                        move = rand() % 4 + 1;
                        while(!checkLegal(i,j,move)){       // check if the random move is legal
                            move = rand() % 4 + 1;
                        }               
                        grid[i][j]->moved = 1;
                        switch(move){                       // move based on the direction
                            case 1:
                                
                                if(grid[i][j+1] != NULL && j+1 < WORLDSIZE){

                                    while(grid[i][j]->getHP() > 0 && grid[i][j+1]->getHP() > 0){
                                        
                                        dmg = grid[i][j]-> getDamage(); // calculate damage
                                        HitMessage(grid[i][j] , grid[i][j+1],dmg);      // display message

                                        if(grid[i][j] ->getHP() <= 0){      // if the attacker is kamikaze it dies so null the pointer
                                            cout << grid[i][j]->getName() << " is dead" << endl;
                                            delete grid[i][j];
                                            grid[i][j] = NULL;
                                        }
                                        
                                        grid[i][j+1]->takeDamage(dmg);      // receiver robot takes the damage
                                        if(grid[i][j+1] -> getHP() <= 0 && grid[i][j] != NULL){
                                            cout << grid[i][j+1]->getName() << " is dead" << endl;  // display message
                                            delete grid[i][j+1];    // free memory
                                            grid[i][j+1] = NULL;
                                            if(grid[i][j] != NULL)
                                            setAt(i,j+1,grid[i][j]);        // set the location if the attacker is alive                                
                                            grid[i][j] = NULL;                                            
                                            break;
                                        }else if( grid[i][j] != NULL && grid[i][j]->getHP() > 0 ){  // receivers turn on attack                                         
                                            dmg = grid[i][j+1]-> getDamage();
                                            HitMessage(grid[i][j+1] , grid[i][j],dmg);
                                            grid[i][j]->takeDamage(dmg);
                                            if( grid[i][j] != NULL && grid[i][j] -> getHP() <= 0){
                                                cout << grid[i][j]->getName() << " is dead" << endl; 
                                                delete grid[i][j];                                                                           
                                                grid[i][j] = NULL;                                               
                                                break;
                                            }
                                        }else{
                                            delete grid[i][j];                                                                           
                                            grid[i][j] = NULL; 
                                        }

                                    }
                                
                                }else if(j+1 < WORLDSIZE){  // if there is no robot occupying the direction we just move
                                    setAt(i,j+1,grid[i][j]);
                                    
                                    grid[i][j] = NULL;
                                }
                               

                            break;
                            case 2:
                                if(grid[i][j-1] != NULL && j-1 >= 0){
                                     while(grid[i][j]->getHP() > 0 && grid[i][j-1]->getHP() > 0){
                                        dmg = grid[i][j]-> getDamage();
                                        HitMessage(grid[i][j] , grid[i][j-1],dmg);
                                        if(grid[i][j] ->getHP() <= 0){
                                            cout << grid[i][j]->getName() << " is dead" << endl;
                                            delete grid[i][j];
                                            grid[i][j] = NULL;
                                        }
                                        grid[i][j-1]->takeDamage(dmg);

                                        if(grid[i][j-1] -> getHP() <= 0 && grid[i][j] != NULL){
                                            cout << grid[i][j+1]->getName() << " is dead" << endl;
                                            delete grid[i][j-1];
                                            grid[i][j-1] = NULL;
                                            if(grid[i][j] != NULL)
                                            setAt(i,j-1,grid[i][j]);                                      
                                            grid[i][j] = NULL;
                                            break;
                                        }else if(grid[i][j] != NULL && grid[i][j]->getHP() > 0){                                           
                                            dmg = grid[i][j-1]-> getDamage();
                                            HitMessage(grid[i][j-1] , grid[i][j],dmg);
                                            
                                            grid[i][j]->takeDamage(dmg);
                                            if( grid[i][j] != NULL && grid[i][j] -> getHP() <= 0){
                                                cout << grid[i][j]->getName() << " is dead" << endl;  
                                                delete grid[i][j];                                                                           
                                                grid[i][j] = NULL;                                              
                                                break;
                                            }
                                        }else{
                                            delete grid[i][j];                                                                           
                                            grid[i][j] = NULL; 
                                        }

                                    }
                                }else if(j-1 >= 0){
                                    setAt(i,j-1,grid[i][j]);
                                    
                                    grid[i][j] = NULL;
                                }
                               

                            break;
                            case 3:

                                if(grid[i+1][j] != NULL && i+1 < WORLDSIZE){
                                    while(grid[i][j]->getHP() > 0 && grid[i+1][j]->getHP() > 0){
                                        dmg = grid[i][j]-> getDamage();
                                        HitMessage(grid[i][j] , grid[i+1][j],dmg);
                                        if(grid[i][j] ->getHP() <= 0){
                                            cout << grid[i][j]->getName() << " is dead" << endl;
                                            delete grid[i][j];
                                            grid[i][j] = NULL;
                                        }
                                        grid[i+1][j]->takeDamage(dmg);
                                        if(grid[i+1][j] -> getHP() <= 0 && grid[i][j] != NULL){
                                            cout << grid[i+1][j]->getName() << " is dead" << endl;
                                            delete grid[i+1][j];
                                            grid[i+1][j] = NULL;
                                            if(grid[i][j] != NULL)
                                            setAt(i+1,j,grid[i][j]);                                      
                                            grid[i][j] = NULL;
                                            break;
                                        }else if( grid[i][j] != NULL && grid[i][j]->getHP() > 0 ){                                           
                                            dmg = grid[i+1][j]-> getDamage();
                                            
                                            HitMessage(grid[i+1][j] , grid[i][j],dmg);

                                                grid[i][j]->takeDamage(dmg);
                                                if( grid[i][j] != NULL && grid[i][j] -> getHP() <= 0){
                                                    cout << grid[i][j]->getName() << " is dead" << endl; 
                                                    delete grid[i][j];                                                                            
                                                    grid[i][j] = NULL;
                                                    
                                                    break;
                                                }
                                            
                                        }else{
                                            delete grid[i][j];
                                            grid[i][j] = NULL;
                                        }

                                    }
                                }else if(i+1 < WORLDSIZE){ 
                                    setAt(i+1,j,grid[i][j]);
               
                                    grid[i][j] = NULL;
                                }
                                

                            break;
                            case 4:
                                
                                if(grid[i-1][j] != NULL && i-1 >= 0){
                                    while(grid[i][j]->getHP() > 0 && grid[i-1][j]->getHP() > 0){
                                        dmg = grid[i][j]-> getDamage();
                                        HitMessage(grid[i][j] , grid[i-1][j],dmg);
                                        if(grid[i][j] ->getHP() <= 0){
                                            cout << grid[i][j]->getName() << " is dead" << endl;
                                            delete grid[i][j];
                                            grid[i][j] = NULL;                                           
                                        }
                                        grid[i-1][j]->takeDamage(dmg);
                                        if(grid[i-1][j] -> getHP() <= 0 && grid[i-1][j] != NULL){
                                            cout << grid[i-1][j]->getName() << " is dead" << endl;
                                            delete grid[i-1][j];
                                            grid[i-1][j] = NULL;
                                            if(grid[i][j] != NULL)
                                            setAt(i-1,j,grid[i][j]);                                
                                            grid[i][j] = NULL;
                                            break;
                                        }else if(grid[i][j] != NULL && grid[i][j]->getHP() > 0){                                           
                                            dmg = grid[i-1][j]-> getDamage();
                                            HitMessage(grid[i-1][j] , grid[i][j],dmg);
                                            grid[i][j]->takeDamage(dmg);
                                            if(grid[i][j] != NULL && grid[i][j] -> getHP() <= 0 ){
                                                cout << grid[i][j]->getName() << " is dead" << endl; 
                                                delete grid[i][j];                                                                            
                                                grid[i][j] = NULL;
                                                
                                                break;
                                            
                                            }
                                        }else{
                                            delete grid[i][j];                                                                            
                                            grid[i][j] = NULL;
                                        }

                                    }
                  
                                }else if(i-1 >= 0){
                                    setAt(i-1,j,grid[i][j]);
                             
                                    grid[i][j] = NULL;
                                }
                                
                            break;
                            default:
                            break;
                        }
                    }
                    
                }
            }
        }
        for(i = 0; i < WORLDSIZE; i++){
            for(j = 0; j < WORLDSIZE; j++){
                if(grid[i][j] != NULL){
                    grid[i][j]->moved = 0;
                }
            }
        }
    }
    bool CheckGrid(){       // check on grid to see if the simulation is over
        int count = 0;
        for(int i = 0; i < WORLDSIZE ; i++){
            for(int j = 0; j < WORLDSIZE ; j++){
                if(grid[i][j] != NULL) count++;
                if(count > 1) break;
            }
            if(count > 1) break;
        }
        if(count == 1 || count == 0){   // robots left is 1 or 0 (kamikaze case)
            return true;
        }
        return false;
    }
    

};

string generateName(const string& type, int sequence){  // couldnt use this function
    return type + "_" + to_string(sequence);
}

int main(){
    World w;
    srand(time(0));
    int fakegrid[WORLDSIZE][WORLDSIZE];             
    
    /*
    ==============================
    fakegrid to keep track of the positions already occupied
    ==============================
    */
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            fakegrid[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int rand1 = rand() % WORLDSIZE;
            int rand2 = rand() % WORLDSIZE;
            while (fakegrid[rand1][rand2] == 1) {
                rand1 = rand() % WORLDSIZE;
                rand2 = rand() % WORLDSIZE;
            }
            fakegrid[rand1][rand2] = 1;
            switch (i) {
                case 0: {
                    optimusprime* A = new optimusprime("prime");    // setting the robots place 5 for each loop
                    w.setAt(rand1, rand2, A);
                    break;
                }
                case 1: {
                    robocop* B = new robocop("robocop");
                    w.setAt(rand1, rand2, B);
                    break;
                }
                case 2: {
                    kamikaze* C = new kamikaze("kamikaze");
                    w.setAt(rand1, rand2, C);
                    break;
                }
                case 3: {
                    roomba* D = new roomba("roomba");
                    w.setAt(rand1, rand2, D);
                    break;
                }
                case 4: {
                    bulldozer* E = new bulldozer("bulldozer");
                    w.setAt(rand1, rand2, E);
                    break;
                }
                default:
                    break;
            }
        }
    }

    while (!w.CheckGrid()) {                                    // fight loop
        w.FightCycle();
        // w.Display();
    }
    w.Display();

    // Clean up dynamically allocated memory
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            delete w.getAt(i, j);
        }
    }

    return 0;
}