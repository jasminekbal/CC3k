#include "Orc.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>


Orc::Orc(): Enemy(180, 30, 25, 'O') {

}

Orc::~Orc(){

}


void Orc::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Orc::onDeath(){
    return gold;
}


bool Orc::attack(Shade &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Orc::attack(Vampire &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Orc::attack(Troll &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Orc::attack(Drow &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Orc::attack(Goblin &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}

bool Orc::onAttacked(Goblin &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Orc::onAttacked(Drow &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Orc::onAttacked(Shade &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Orc::onAttacked(Troll &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}

bool Orc::onAttacked(Vampire &p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
        this->setHP(this->getHp()-damage);
        return true;
    }
    return false;
}


