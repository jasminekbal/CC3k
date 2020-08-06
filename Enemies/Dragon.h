#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon: public Enemy{
    private:
    char c = 'D';

    public:
    Dragon();
    virtual ~Dragon();
    virtual bool attack(Player &p) override;
    virtual bool onAttacked(Player &p) override;
    virtual std::shared_ptr<Gold> onDeath() override;

};

#endif
