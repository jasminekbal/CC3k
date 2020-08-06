#ifndef ELF_H
#define ELF_H
#include "Enemy.h"

class Drow;

class Elf: public Enemy{

    public:
    Elf();
    virtual ~Elf();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;
    bool onAttacked(Drow &d);

};

#endif
