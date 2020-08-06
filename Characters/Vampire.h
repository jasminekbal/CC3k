#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Dwarf;

class Vampire: public Player {
    public:
    Vampire();
    virtual ~Vampire();
    virtual bool attack(Enemy &e) override;
    bool attack(Dwarf &e);
    virtual bool onAttacked(Enemy &) override;

};

#endif

