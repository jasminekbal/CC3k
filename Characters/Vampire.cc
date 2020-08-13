#include "Vampire.h"
#include "../Enemies/Dragon.h"
#include "../Enemies/Dwarf.h"
#include "../Enemies/Elf.h"
#include "../Enemies/Halfling.h"
#include "../Enemies/Human.h"
#include "../Enemies/Merchant.h"
#include "../Enemies/Orc.h"
#include "../Enemies/Enemy.h"
#include "../Items/Gold.h"
#include <cmath>

Vampire::Vampire(): Player(50, 25, 25, -1){}

Vampire::~Vampire(){
}

bool Vampire::onAttacked(Enemy &e) {
  return e.attack(*this);
}

bool Vampire::baseAtk (Enemy & e){
  bool goesThrough = e.onAttacked(*this);

  if (goesThrough){
    this->changeHp(this->getHp()+5);
  }
  return goesThrough;
}

bool Vampire::baseOnAtk(Enemy & e){
  int damage = ceil((100/(100+ this->getDef()))* e.getAtk());
  this->changeHp(this->getHp()-damage);
  return true;
}

bool Vampire::attack(Dragon &e){
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Dragon &e){
  return this->baseOnAtk(e);
}

bool Vampire::attack(Dwarf &e){
  bool goesThrough = e.onAttacked(*this);

  if (goesThrough){
    this->changeHp(this->getHp()-5);
  }
  return goesThrough;
}

bool Vampire::onAttacked(Dwarf &e){
   return this->baseOnAtk(e);
}

bool Vampire::attack(Elf &e) {
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Elf &e){
   return this->baseOnAtk(e);
}

bool Vampire::attack(Halfling &e) {
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Halfling &e){
   return this->baseOnAtk(e);
}

bool Vampire::attack(Human &e){
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Human &e){
   return this->baseOnAtk(e);
}

bool Vampire::attack(Merchant &e) {
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Merchant &e){
  return this->baseOnAtk(e);
}

bool Vampire::attack(Orc &e) {
  return this->baseAtk(e);
}

bool Vampire::onAttacked(Orc &e){
  return this->baseOnAtk(e);
}

