#ifndef POISONHEALTH_H
#define POISONHEALTH_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class PoisonHP: public Potion {

    public:
    BoostAtk();
    virtual ~BoostAtk();
    void usePotion(std::shared_ptr<Player> p); 
    void usePotion(std::shared_ptr<Drow> d); 
    std::string getMessage();
};

#endif
