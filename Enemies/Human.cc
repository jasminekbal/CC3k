#include "Human.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <iostream>
#include <cmath>
using namespace std;


Human::Human() : Enemy(140, 20, 20, 'H'){
    auto newG = std::make_shared<Gold>(4, true);
    this->setGold(newG);
}

Human::~Human(){

}

bool Human::onAttacked(Player &p){
    return p.attack(*this);
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
    return true;
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
    return baseOnAtk(p);
}

bool Human::onAttacked(Drow &p){
    return baseOnAtk(p);
}

bool Human::onAttacked(Shade &p){
    return baseOnAtk(p);
}

bool Human::onAttacked(Troll &p){
    return baseOnAtk(p);
}

bool Human::onAttacked(Vampire &p){
    return baseOnAtk(p);
} 


void Human::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Human::onDeath(){
    return gold;
}
