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

Elf::Elf():Enemy(140, 30, 10, 'E'){
    auto newG = std::make_shared<Gold>(2, true);
    this->setGold(newG);
}

Elf::~Elf(){}

bool Elf::attack(Player * p){
    if (p->getType()=='D'){
        bool toAtk = this->randAtk();
        if (toAtk){
            p->onAttacked(*this);
            return true;
        } else {
            return false;
        }
    } else {
        bool firstAtk = this->randAtk();
        if (firstAtk){
            p->onAttacked(*this);
        }
        bool secondAtk = this->randAtk();
        if (secondAtk){
            p->onAttacked(*this);
        }

        return firstAtk || secondAtk;
    }
    
}

void Elf::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Elf::onDeath(){
    return gold;
}
