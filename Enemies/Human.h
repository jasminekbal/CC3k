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

    void setGold(std::shared_ptr<Gold> g);
    std::shared_ptr<Gold> onDeath();

};


#endif
