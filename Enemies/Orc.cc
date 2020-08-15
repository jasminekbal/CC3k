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

void Orc::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Orc::onDeath(){
    return gold;
}
