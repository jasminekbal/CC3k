#include "Dragon.h"
#include "../Items/DragonGold.h"

Dragon::Dragon():Enemy(150, 30, 25, 'D'){

}

Dragon::~Dragon(){

}

bool Dragon::attack(Player &p){

}

bool Dragon::onAttacked(Player &p){

}

void Dragon::setGold(std::shared_ptr<DragonGold> g){
    dG = g;
}

std::shared_ptr<Gold> Dragon::onDeath(){
    dG->setCanCollect(true);
    return dG;
}
