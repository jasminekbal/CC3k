#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class Orc: public Enemy{
    private:
    std::shared_ptr<Gold> gold;

    public:
    Orc();
    virtual ~Orc();
    
    virtual bool onAttacked(Player &p) ;
    virtual bool attack(Drow &d) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Drow &d) ;
    virtual bool attack(Goblin &g) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Goblin &g) ;
    virtual bool attack(Shade &s) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Shade &s);
    virtual bool attack(Troll &t) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Troll &t);
    virtual bool attack(Vampire &v) override;  // this returns if the attack was succesful
    virtual bool onAttacked(Vampire &v);
    
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;
};

#endif
