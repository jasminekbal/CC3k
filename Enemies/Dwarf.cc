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

void Dwarf::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Dwarf::onDeath(){
    return gold;
}
