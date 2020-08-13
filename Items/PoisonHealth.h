#ifndef POISONHEALTH_H
#define POISONHEALTH_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class PoisonHP: public Potion {

    public:
    PoisonHP();
    virtual ~PoisonHP();
    void usePotion(std::shared_ptr<Player> p) override; 
};

#endif
