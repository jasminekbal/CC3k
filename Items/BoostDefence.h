#ifndef BOOSTDEFENSE_H
#define BOOSTDEFENSE_H
#include <string>
#include <memory>
#include "Potion.h"

class BoostDef: public Potion {

    public:
    virtual void usePotion(std::shared_ptr<Player> p) override ; 
    virtual void usePotion( std::shared_ptr<Drow> d) override;

};

#endif
