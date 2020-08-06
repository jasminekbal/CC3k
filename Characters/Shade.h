#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade: public Player {
    public:
    Shade();
    virtual ~Shade();
    virtual bool attack(Enemy &e) override;
    virtual bool onAttacked(Enemy &) override;
    int getScore() const; //50% more
};

#endif

