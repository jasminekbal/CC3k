#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Dwarf;

class Vampire: public Player {
    public:
    Vampire();
    virtual ~Vampire();
    
    bool attack(Enemy * e) override;
};

#endif

