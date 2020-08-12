#include "Human.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>


Human::Human() : Enemy(140, 20, 20, 'H'){

}

Human::~Human(){

}

bool Human::attack(Shade &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Human::attack(Vampire &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Human::attack(Troll &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Human::attack(Drow &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Human::attack(Goblin &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}

bool Human::onAttacked(Goblin &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Human::onAttacked(Drow &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Human::onAttacked(Shade &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Human::onAttacked(Troll &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Human::onAttacked(Vampire &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}


void Human::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Human::onDeath(){
    return gold;
}
