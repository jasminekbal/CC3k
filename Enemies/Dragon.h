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
    
    virtual bool attack(Drow &d) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Drow &d) override;
    virtual bool attack(Goblin &g) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Goblin &g) override;
    virtual bool attack(Shade &s) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Shade &s) override;
    virtual bool attack(Troll &t) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Troll &t) override;
    virtual bool attack(Vampire &v) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Vampire &v) override;

    void setGold(std::shared_ptr<DragonGold> g);
    virtual std::shared_ptr<Gold> onDeath() override;

};

#endif
