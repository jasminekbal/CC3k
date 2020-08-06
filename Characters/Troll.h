#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

class Orc;

class Troll: public Player{
    public:
    Troll();
    virtual ~Troll();
    virtual bool attack(Enemy &e) override;
    virtual bool onAttacked(Enemy &e) override;
    virtual bool onAttacked(Orc &o);

};

#endif

