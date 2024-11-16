#ifndef ROBOTS_H
#define ROBOTS_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Robot {
private:
    int hp;
    int strength;
    string name;
public:
    int moved;
    Robot();
    Robot(int newHP, int newStrength, string newName);
    void setHP(int num);
    void setStrength(int num);
    int getStrength();
    int getHP();
    string getName();
    void setName(string newName);
    void takeDamage(int damage);
    virtual int getDamage() = 0;
    virtual int getType1() = 0;
};

class Humanic : public Robot {
private:
    int type1;
public:
    Humanic();
    virtual int getType1() = 0;
    virtual int getDamage() = 0;
};

class OptimusPrime : public Humanic {
private:
    int type1;
public:
    OptimusPrime();
    OptimusPrime(string newName);
    int getType1() override;
    int getDamage() override;
};

class Robocop : public Humanic {
private:
    int type1;
public:
    Robocop();
    Robocop(string newName);
    int getType1() override;
    int getDamage() override;
};

class Roomba : public Robot {
private:
    int type1;
public:
    Roomba();
    Roomba(string newName);
    int getType1() override;
    int getDamage() override;
};

class Kamikaze : public Robot {
private:
    int type1;
public:
    Kamikaze();
    Kamikaze(string newName);
    int getType1() override;
    int getDamage() override;
};

class Bulldozer : public Robot {
private:
    int type1;
public:
    Bulldozer();
    Bulldozer(string newName);
    int getType1() override;
    int getDamage() override;
};

#endif 