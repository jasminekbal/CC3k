#include   "Merchant.h"

Merchant::Merchant(): Enemy(30, 70, 5, 'M'){
    isHostile = 0;
}

Merchant::~Merchant(){

}

bool Merchant::attack(Player &p){

}

bool Merchant::onAttacked(Player &p){

}

void Merchant::makeHostile(){
    isHostile = 1;
}
