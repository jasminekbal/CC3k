#include "Halfling.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>

Halfling::Halfling():Enemy(100, 15, 20, 'L'){
}

Halfling::~Halfling(){
   
}

bool Halfling::onAttacked( Player & p ){
    p.attack(*this);
}

// will do later
bool Halfling::attack(Shade &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Halfling::attack(Vampire &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Halfling::attack(Troll &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Halfling::attack(Drow &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Halfling::attack(Goblin &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}

bool Halfling::onAttacked(Goblin &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Halfling::onAttacked(Drow &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Halfling::onAttacked(Shade &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Halfling::onAttacked(Troll &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Halfling::onAttacked(Vampire &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}


void Halfling::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Halfling::onDeath(){
    return gold;
}
