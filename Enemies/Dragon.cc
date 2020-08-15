#include "Dragon.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>

using namespace std;

Dragon::Dragon():Enemy(150, 30, 25, 'D'){
    dG = nullptr;
    hasAttacked = false;
}

Dragon::~Dragon(){
}

void Dragon::setGold(std::shared_ptr<DragonGold> g){
    dG = g;
}

std::shared_ptr<Gold> Dragon::getGold(){
    return dG;
}

std::shared_ptr<Gold> Dragon::onDeath(){
    dG->setCanCollect(true);
    dG->setDragon(nullptr);
    dG = nullptr;
    return nullptr;
}


void Dragon::setHasAttacked( bool b ){
    hasAttacked = b;
}

bool Dragon::getHasAttacked(){
    return hasAttacked;
}

