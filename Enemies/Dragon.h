#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class DragonGold;

class Dragon: public Enemy{
    private:
    char c = 'D';
    std::shared_ptr<DragonGold> dG;

    public:
    Dragon();
    virtual ~Dragon();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;
    void Dragon::setGold(std::shared_ptr<DragonGold> g);
    virtual std::shared_ptr<Gold> onDeath();

};

#endif
