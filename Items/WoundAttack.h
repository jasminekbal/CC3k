#ifndef WOUNDATTACK_H
#define WOUNDATTACK_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class WoundAtk: public Potion {

    public:
    WoundAtk();
    virtual ~WoundAtk();
    void usePotion(std::shared_ptr<Player> p) override; 
    void usePotion(std::shared_ptr<Drow> d) override; 

};

#endif
