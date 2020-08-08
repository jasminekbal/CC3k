#include "Halfling.h"

Halfling::Halfling():Enemy(100, 15, 20, 'L'){
}

Halfling::~Halfling(){

}


// will do later
bool Halfling::attack(Player &p){
    return false;
}

bool onAttacked(Player &p){
    return false;
}

