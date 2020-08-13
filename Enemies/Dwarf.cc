#include "Dwarf.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>


Dwarf::Dwarf(): Enemy(100, 20, 30, 'W'){}

Dwarf::~Dwarf(){}

bool Dwarf::attack(Drow &p) {
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}  

bool Dwarf::onAttacked(Player &p){
    return p.attack(*this);
}

bool Dwarf::onAttacked(Drow &p){
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}

bool Dwarf::attack(Goblin &p) {
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}
bool Dwarf::onAttacked(Goblin &p){
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}
bool Dwarf::attack(Shade &p) {
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}
bool Dwarf::onAttacked(Shade &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}
bool Dwarf::attack(Troll &p) {
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}
bool Dwarf::onAttacked(Troll &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}
bool Dwarf::attack(Vampire &p) {
    bool toAtk = this->randAtk();
    if (toAtk){
        p.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}

bool Dwarf::onAttacked(Vampire &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}

void Dwarf::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Dwarf::onDeath(){
    return gold;
}
