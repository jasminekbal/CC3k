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
    auto newG = std::make_shared<Gold>(2, true);
    this->setGold(newG);
}

Orc::~Orc(){

}

bool Orc::onAttacked(Player &p){
    return p.attack(*this);
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
        return baseOnAtk(p);
}

bool Orc::onAttacked(Drow &p){
        return baseOnAtk(p);
}

bool Orc::onAttacked(Shade &p){
        return baseOnAtk(p);
}

bool Orc::onAttacked(Troll &p){
        return baseOnAtk(p);
}

bool Orc::onAttacked(Vampire &p){
        return baseOnAtk(p);
}


