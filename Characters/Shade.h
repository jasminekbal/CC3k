#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade: public Player {
    private:
    /*
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);
    */
    public:
    Shade();
    virtual ~Shade();
    int getScore() const override; //50% more
};

#endif

