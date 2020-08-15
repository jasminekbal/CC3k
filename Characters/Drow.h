#ifndef DROW_H
#define DROW_H
#include "Player.h"

class Drow: public Player{
    private:
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);

    public:
    Drow();
    virtual ~Drow();
};

#endif
