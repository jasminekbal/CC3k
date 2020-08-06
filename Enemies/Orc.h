#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class Orc: public Enemy{
    public:
    Orc();
    virtual ~Orc();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;
};

#endif
