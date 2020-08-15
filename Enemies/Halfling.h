#ifndef HALFLING_H
#define HALFLING_H
#include "Enemy.h"

class Halfling: public Enemy{
    
    std::shared_ptr<Gold> gold;

    public:
    Halfling();
    virtual ~Halfling();
    
    virtual bool onAttacked(Player & p) override;
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;
};

#endif