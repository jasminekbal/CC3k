#ifndef HALFLING_H
#define HALFLING_H
#include "Enemy.h"

class Halfling: public Enemy{

    public:
    Halfling();
    virtual ~Halfling();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;

};

#endif