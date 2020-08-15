#ifndef HUMAN_H
#define HUMAN_H
#include "Enemy.h"

class Ground;

class Human: public Enemy{

    private:
    std::shared_ptr<Gold> gold;

    public:
    Human();
    virtual ~Human();
    
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;

};


#endif
