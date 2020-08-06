#ifndef HUMAN_H
#define HUMAN_H
#include "Enemy.h"

class Tile;

class Human: public Enemy{

    private:
    std::shared_ptr<Tile> location;

    public:
    Human();
    virtual ~Human();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;
    virtual std::shared_ptr<Gold> onDeath() override;
};


#endif
