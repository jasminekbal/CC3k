#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

class Dwarf: public Enemy{
    std::shared_ptr<Gold> gold;

    public:
    Dwarf();
    virtual ~Dwarf();
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;


};

#endif

