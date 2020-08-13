#include "Dwarf.h"
#include "../Characters/Player.h"
#include "../Items/Gold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>


Dwarf::Dwarf(): Enemy(100, 20, 30, 'W'){
    auto newG = std::make_shared<Gold>(2, true);
    setGold(newG);
}

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
    return baseOnAtk(p);
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
    return baseOnAtk(p);
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
    return baseOnAtk(p);
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
    return baseOnAtk(p);
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
    return baseOnAtk(p);
}

void Dwarf::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Dwarf::onDeath(){
    return gold;
}
