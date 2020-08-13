#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class Drow;

class WoundDef: public Potion {

    public:
    WoundDef();
    virtual ~WoundDef();
    void usePotion(std::shared_ptr<Player> p) override; 
};

#endif

