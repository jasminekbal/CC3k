#include "Orc.h"


Orc::Orc(): Enemy(180, 30, 25, 'O') {

}

Orc::~Orc(){

}

bool Orc::attack(Player &p){
    return false;
}

bool Orc::onAttacked(Player &p){
    return false;
}   
