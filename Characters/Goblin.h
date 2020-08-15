#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

class Goblin: public Player{
    private:

    bool onAttackedOrc(Enemy & e);

    public:
    Goblin(); //to be called by newPlayer to create player for next round
    virtual ~Goblin();
    bool attack(Enemy * e ) override;
    bool onAttacked(Enemy & e) override;
};


#endif
