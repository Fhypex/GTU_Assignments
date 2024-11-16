#include "world.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


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
World::World() {
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            grid[i][j] = nullptr;
        }
    }
}

World::~World() {
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
            }
        }
    }
}

Robot* World::getAt(int x, int y) {
    if (x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE) {
        return grid[x][y];
    }
    return nullptr;
}

void World::setAt(int x, int y, Robot* object) {
    if (x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE) {
        grid[x][y] = object;
    } 
}

void World::Display() {
    cout << endl << endl;
    for (int j = 0; j < WORLDSIZE; j++) {
        for (int i = 0; i < WORLDSIZE; i++) {
            if (grid[i][j] == nullptr) {
                cout << "O ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

void World::HitMessage(Robot* obj1, Robot* obj2, int dmg) {
    cout << obj1->getName() << " " << obj1->getHP() << " hits " << obj2->getName() << " " << obj2->getHP() << " with " << dmg << endl;
}

void World::FightCycle() {
    int move, dmg, x, y, j_increment, i_increment;
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            x = i;
            y = j;
            j_increment = 0;
            i_increment = 0;
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->moved == 0) {
                    move = rand() % 4 + 1;
                    while (!checkLegal(i, j, move)) {
                        move = rand() % 4 + 1;
                    }
                    grid[i][j]->moved = 1;
                    switch (move) {
                        case 1:
                            // Handle movement and combat logic for move 1
                            break;
                        case 2:
                            // Handle movement and combat logic for move 2
                            break;
                        case 3:
                            // Handle movement and combat logic for move 3
                            break;
                        case 4:
                            // Handle movement and combat logic for move 4
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->moved = 0;
            }
        }
    }
}

bool World::CheckGrid(){
    int count = 0;
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != nullptr) {
                count++;
                if (count > 1) {
                    break;
                }
            }
        }
        if (count > 1) {
            break;
        }
    }
    if (count == 1 || count == 0) {
        return true;
    }
    return false;
}
