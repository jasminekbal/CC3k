#include "Human.h"

Human::Human() : Enemy(140, 20, 20, 'H'){

}

Human::~Human(){

}

//
bool Human::attack(Player &p){
    return false;
}

bool Human::onAttacked(Player &p){
    return false;
}

//human doesn't have its own gold pointer, what does this return?
std::shared_ptr<Gold> Human::onDeath(){
    return;
}

void Human::setLocation(std::shared_ptr<Ground> g){
    location = g;
}

std::shared_ptr<Ground> Human::getLocation(){
    return  location;
}
