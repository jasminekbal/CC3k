#include   "Merchant.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>

Merchant::Merchant(): Enemy(30, 70, 5, 'M'){
    auto newG = std::make_shared<Gold>(2, true);
    this->setGold(newG);
}

Merchant::~Merchant(){

}

bool Merchant:: isHostile(){
    return Merchant::hostile;
}

void Merchant::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Merchant::onDeath(){
    return gold;
}

bool Merchant::onAttacked(Player &p) {
    return p.attack(*this);
}

bool Merchant::attack(Shade &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Merchant::attack(Vampire &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Merchant::attack(Troll &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Merchant::attack(Drow &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}


bool Merchant::attack(Goblin &p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}

bool Merchant::onAttacked(Goblin &p){
    return baseOnAtk(p);
}

bool Merchant::onAttacked(Drow &p){
    return baseOnAtk(p);
}

bool Merchant::onAttacked(Shade &p){
    return baseOnAtk(p);
}

bool Merchant::onAttacked(Troll &p){
    return baseOnAtk(p);
}

bool Merchant::onAttacked(Vampire &p){
    return baseOnAtk(p);
}

void Merchant::makeHostile(){
      Merchant::hostile = true;
}

bool Merchant::hostile = false;
