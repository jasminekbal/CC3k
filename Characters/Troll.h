#ifndef TROLL_H
#define TROLL_H
#include "Player.h"


class Troll: public Player{
    private:
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);

    
    public:
    Troll();
    virtual ~Troll();
};

#endif

