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
    auto newG = std::make_shared<Gold>(4, false);
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

void Merchant::makeHostile(){
      Merchant::hostile = true;
}

bool Merchant::hostile = false;
