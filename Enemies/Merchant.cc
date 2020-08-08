#include   "Merchant.h"

Merchant::Merchant(): Enemy(30, 70, 5, 'M'){

}

Merchant::~Merchant(){

}

bool Merchant::attack(Player &p){

}

bool Merchant::onAttacked(Player &p){

}

bool Merchant::hostile(){
    return isHostile;
}

void Merchant::makeHostile(){
    isHostile = true;
}
