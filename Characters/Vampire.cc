#include "Vampire.h"

Vampire::Vampire(): Player(50, 25, 25, -1){}

Vampire::~Vampire(){

}

//will do later
bool Vampire::attack(Enemy &e){
  return false;
}

bool Vampire::attack(Dwarf &e){
  return false;
}

bool Vampire::onAttacked(Enemy &){
  return false;
}
