#include <iostream>
#include "World.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(0));
    World w;

    Robot* A = new OptimusPrime("prime");
    w.setAt(1, 4, A);

    Robot* B = new Robocop("robocop");
    w.setAt(3, 6, B);

    Robot* C = new Kamikaze("kamikaze");
    w.setAt(8, 8, C);

    Robot* D = new Roomba("roomba");
    w.setAt(5, 5, D);

    Robot* E = new Bulldozer("bulldozer");
    w.setAt(4, 7, E);

    while (!w.CheckGrid()) {
        w.FightCycle();
     //   w.Display();
    }

    delete A;
    delete B;
    delete C;
    delete D;
    delete E;

    return 0;
}