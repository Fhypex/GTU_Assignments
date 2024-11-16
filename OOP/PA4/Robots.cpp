#include "robots.h"
#include <ctime>

// Robot class implementation,

Robot::Robot() {
    moved = 0;
    hp = 1;
    strength = 1;
    name = "default";
}

Robot::Robot(int newHP, int newStrength, std::string newName) {
    moved = 0;
    hp = newHP;
    strength = newStrength;
    name = newName;
}

void Robot::setHP(int num) {
    hp = num;
}

void Robot::setStrength(int num) {
    strength = num;
}

int Robot::getStrength() {
    return strength;
}

int Robot::getHP() {
    return hp;
}

std::string Robot::getName() {
    return name;
}

void Robot::setName(std::string newName) {
    name = newName;
}

void Robot::takeDamage(int damage) {
    hp -= damage;
}

// Humanic class implementation
Humanic::Humanic() {
    type1 = -1;
}

// OptimusPrime class implementation
OptimusPrime::OptimusPrime() {
    type1 = 0;
    setHP(100);
    setStrength(100);
}

OptimusPrime::OptimusPrime(std::string newName) {
    type1 = 0;
    setHP(100);
    setStrength(100);
    setName(newName);
}

int OptimusPrime::getType1() {
    return type1;
}

int OptimusPrime::getDamage() {
    int rand1 = rand() % 20;
    int rand2 = rand() % getStrength() + 1;
    int rand3 = rand() % 10;
    
    if(rand3 == 0) {
        rand2 += 50;
    }
    if(rand1 < 3) {
        std::cout << getName() << " attacks for " << rand2 * 2 << " points!" << std::endl;
        return rand2 * 2;
    } else {
        std::cout << getName() << " attacks for " << rand2 << " points!" << std::endl;
        return rand2;
    }
}

// Robocop class implementation
Robocop::Robocop() {
    type1 = 1;
    setHP(40);
    setStrength(30);
}

Robocop::Robocop(std::string newName) {
    type1 = 1;
    setHP(40);
    setStrength(30);
    setName(newName);
}

int Robocop::getType1() {
    return type1;
}

int Robocop::getDamage() {
    int rand1 = rand() % 10;
    int rand2 = rand() % getStrength() + 1;
    if(rand1 == 0) {
        rand2 += 50;
    }
    std::cout << getName() << " attacks for " << rand2 << " points!" << std::endl;
    return rand2;           
}

// Roomba class implementation
Roomba::Roomba() {
    type1 = 2;
    setHP(10);
    setStrength(3);
}

Roomba::Roomba(std::string newName) {
    type1 = 2;
    setHP(10);
    setStrength(3);
    setName(newName);
}

int Roomba::getType1() {
    return type1;
}

int Roomba::getDamage() {
    int dmg1 = rand() % getStrength() + 1;
    int dmg2 = rand() % getStrength() + 1;
    std::cout << getName() << " attacks for " << dmg1 + dmg2 << " points!" << std::endl;
    return dmg1 + dmg2;
}

// Kamikaze class implementation
Kamikaze::Kamikaze() {
    type1 = 4;
    setHP(10);
}

Kamikaze::Kamikaze(std::string newName) {
    type1 = 4;
    setHP(10);
    setName(newName);
}

int Kamikaze::getType1() {
    return type1;
}

int Kamikaze::getDamage() {
    std::cout << getName() << " attacks for " << getHP() << " points!" << std::endl;
    takeDamage(10);
    return getHP();
}

// Bulldozer class implementation
Bulldozer::Bulldozer() {
    type1 = 3;
    setStrength(50);
    setHP(200);
}

Bulldozer::Bulldozer(std::string newName) {
    type1 = 3;
    setHP(200);
    setStrength(50);
    setName(newName);
}

int Bulldozer::getType1() {
    return type1;
}

int Bulldozer::getDamage() {
    int dmg = rand() % getStrength() + 1;
    std::cout << getName() << " attacks for " << dmg << " points!" << std::endl;
    return dmg;
}
