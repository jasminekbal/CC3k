#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class Drow;

class BoostAtk: public Potion {

    public:
    BoostAtk();
    virtual ~BoostAtk();
    virtual void usePotion(std::shared_ptr<Player> p) override; 
    virtual void usePotion( std::shared_ptr<Drow> d) override;

};

#endif
