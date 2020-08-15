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
    auto newG = std::make_shared<Gold>(4, false);
    this->setGold(newG);
}

Human::~Human(){

}

void Human::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Human::onDeath(){
    return gold;
}

