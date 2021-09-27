#include "Competition.h"
#include <cstdlib> //srand
#include <iostream> //use cout
#include <iomanip> //setw
using namespace std; //simplify std::cout by cout, or endl
Competition::Competition(){
    srand(1);
    rabbit = new Hare;
    turtle = new Tortoise;
    track = new Road;
}

Competition::Competition(Hare* hare, Tortoise* tor, int length){
    srand(1);
    this -> rabbit = new Hare(hare -> getPattern(), hare -> getPatternLength(), hare -> getPosition());
    this -> turtle = new Tortoise(tor -> getPattern(), tor -> getPatternLength(), tor -> getPosition());
    track = new Road(length);
}

Competition::~Competition(){
    delete rabbit;
    rabbit = 0;
    delete turtle;
    turtle = 0;
    delete track;
    track = 0;
}

void Competition::start(){
    int lastBlock = track -> getLastBlock();

    int round = 1;

    while(rabbit -> getPosition() < lastBlock && turtle -> getPosition() < lastBlock){
        rabbit -> move();

        if(rabbit -> getPattern() < 0){
            rabbit -> setPosition(0);
        }
        else if(rabbit -> getPosition() > lastBlock){
            rabbit -> setPosition(lastBlock);
        }

        //TODO: move tor!!
        turtle -> move();

        if(turtle -> getPosition() < 0){
            turtle -> setPosition(0);
        }
        else if(turtle -> getPosition() > lastBlock){
            turtle -> setPosition(lastBlock);
        }

        track->mark(rabbit->getPosition(), 'H');
        track->mark(turtle->getPosition(), 'T');

        cout << setw(3) << round << " ";
        cout << track->toString() << endl;

        if (rabbit->getPosition() == turtle->getPosition()){
            cout << "Ouch, Tortoise bites Hare." << endl;
        }

        round++;
        track->mark(rabbit->getPosition(), ' ');
        track->mark(turtle->getPosition(), ' ');
    }
    if (rabbit->getPosition()==lastBlock && turtle->getPosition()==lastBlock){
        cout << "It is a tie." << endl;
    }
    else if (rabbit->getPosition() == lastBlock){
        cout << "Yuck, hare wins." << endl;
    }
    else if (turtle->getPosition() == lastBlock){
        cout << "Yay!!! tortoise wins!" << endl;
    }
}