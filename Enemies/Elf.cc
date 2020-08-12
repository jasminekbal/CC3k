#include "Elf.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>

Elf::Elf():Enemy(140, 30, 10, 'E'){}

Elf::~Elf(){}


bool Elf::attack(Drow &d){
    bool toAtk = this->randAtk();
    if (toAtk){
        d.onAttacked(*this);
        return true;
    } else {
        return false;
    }
}
 
bool Elf::onAttacked(Drow &p){
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}

bool Elf::attack(Goblin &p) {
    bool firstAtk = this->randAtk();
    if (firstAtk){
        p.onAttacked(*this);
    }
    bool secondAtk = this->randAtk();
    if (secondAtk){
        p.onAttacked(*this);
    }

    return firstAtk || secondAtk;
}


bool Elf::onAttacked(Goblin &p){
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}
bool Elf::attack(Shade &p) {
    bool firstAtk = this->randAtk();
    if (firstAtk){
        p.onAttacked(*this);
    }
    bool secondAtk = this->randAtk();
    if (secondAtk){
        p.onAttacked(*this);
    }

    return firstAtk || secondAtk;
}

bool Elf::onAttacked(Shade &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}

bool Elf::attack(Troll &p) {
    bool firstAtk = this->randAtk();
    if (firstAtk){
        p.onAttacked(*this);
    }
    bool secondAtk = this->randAtk();
    if (secondAtk){
        p.onAttacked(*this);
    }

    return firstAtk || secondAtk;
}


bool Elf::onAttacked(Troll &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}


bool Elf::attack(Vampire &p) {
    bool firstAtk = this->randAtk();
    if (firstAtk){
        p.onAttacked(*this);
    }
    bool secondAtk = this->randAtk();
    if (secondAtk){
        p.onAttacked(*this);
    }

    return firstAtk || secondAtk;
}

bool Elf::onAttacked(Vampire &p) {
    int damage = ceil((100/(100+ this->getDef()))* p.getAtk());
    this->setHP(this->getHp()-damage);
    return true;
}


void Elf::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Elf::onDeath(){
    return gold;
}
