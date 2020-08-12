#include "Drow.h"
#include "../Enemies/Dragon.h"
#include "../Enemies/Dwarf.h"
#include "../Enemies/Elf.h"
#include "../Enemies/Halfling.h"
#include "../Enemies/Human.h"
#include "../Enemies/Merchant.h"
#include "../Enemies/Orc.h"
#include "../Enemies/Enemy.h"
#include <cmath>


Drow::Drow():Player(150, 25, 15, 150){

}

Drow::~Drow(){

}

bool Drow::baseAtk (Enemy & e){
  bool myAtk = true;
  bool goesThrough = e.onAttacked(*this);
  return myAtk and goesThrough;
}

bool Drow::baseOnAtk(Enemy & e){
  int damage = ceil((100/(100+ this->getDef()))* e.getAtk());
  this->changeHp(this->getHp()-damage);
  return true;
}

bool Drow::attack(Dragon &e){
  return this->baseAtk(e);
}

bool Drow::onAttacked(Dragon &e){
  return this->baseOnAtk(e);
}

bool Drow::attack(Dwarf &e){
  return this->baseAtk(e);
}

bool Drow::onAttacked(Dwarf &e){
   return this->baseOnAtk(e);
}

bool Drow::attack(Elf &e) {
  return this->baseAtk(e);
}

bool Drow::onAttacked(Elf &e){
   return this->baseOnAtk(e);
}

bool Drow::attack(Halfling &e) {
  return this->baseAtk(e);
}

bool Drow::onAttacked(Halfling &e){
   return this->baseOnAtk(e);
}

bool Drow::attack(Human &e){
  return this->baseAtk(e);
}

bool Drow::onAttacked(Human &e){
   return this->baseOnAtk(e);
}

bool Drow::attack(Merchant &e) {
  return this->baseAtk(e);
}

bool Drow::onAttacked(Merchant &e){
  return this->baseOnAtk(e);
}

bool Drow::attack(Orc &e) {
  return this->baseAtk(e);
}

bool Drow::onAttacked(Orc &e){
   return this->baseOnAtk(e);
}


