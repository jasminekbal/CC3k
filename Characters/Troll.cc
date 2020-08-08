#include "Troll.h"

Troll::Troll():Player(120, 25, 15, 120){

}

Troll::~Troll(){

}


//will do later
bool Troll::attack(Enemy &e) {
  return false;
}

bool Troll::onAttacked(Enemy &e){
  return false;
}

bool Troll::onAttacked(Orc &o){
  return false;
}

