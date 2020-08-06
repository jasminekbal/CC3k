#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

class Dwarf: public Enemy{
        
    public:
    Dwarf();
    virtual ~Dwarf();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;

};

#endif

