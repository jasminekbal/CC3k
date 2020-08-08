#include "Drow.h"

Drow::Drow():Player(150, 25, 15, 150){

}

Drow::~Drow(){

}


//will do later
bool Drow::attack(Enemy &e){
  return false;
}

bool Drow::onAttacked(Enemy &e){
  return false;
}

