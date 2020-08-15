#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class DragonGold;

class Dragon: public Enemy{
    private:
    char c = 'D';
    std::shared_ptr<DragonGold> dG;
    bool hasAttacked;

    public:
    Dragon();
    virtual ~Dragon();
    void setGold(std::shared_ptr<DragonGold> g);
    std::shared_ptr<Gold> getGold();
    virtual std::shared_ptr<Gold> onDeath() override;

    virtual void setHasAttacked( bool b ) override;
    virtual bool getHasAttacked() override;

};

#endif
