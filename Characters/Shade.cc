#include "Shade.h"

Shade::Shade(): Player(125, 25, 25, 125){
}

Shade::~Shade(){

}

//will do later
bool Shade::attack(Enemy &e){

}

bool Shade::onAttacked(Enemy &e){

}

int Shade::getScore() const{
    return this->getScore() + this->getScore()/2;
}

