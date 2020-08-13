#ifndef BOOSTDEFENSE_H
#define BOOSTDEFENSE_H
#include <string>
#include <memory>
#include "Potion.h"

class BoostDef: public Potion {

    public:
    BoostDef();
    virtual ~BoostDef();
    virtual void usePotion(std::shared_ptr<Player> p) override ; 
};

#endif
