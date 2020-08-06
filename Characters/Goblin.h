#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

class Goblin: public Player{

    public:
    Goblin(); //to be called by newPlayer to create player for next round
    virtual ~Goblin();
    virtual bool attack(Enemy &e) override;
    virtual bool onAttacked(Enemy &e) override;

};


#endif
