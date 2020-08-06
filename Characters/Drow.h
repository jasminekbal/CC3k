#ifndef DROW_H
#define DROW_H
#include "Player.h"

class Drow: public Player{
    public:
    Drow();
    virtual ~Drow();
    virtual bool attack(Enemy &e) override;
    virtual bool onAttacked(Enemy &e) override;

};

#endif
