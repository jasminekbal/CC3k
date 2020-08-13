#include "Troll.h"
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


Troll::Troll():Player(120, 25, 15, 120){

}

Troll::~Troll(){

}

bool Troll::onAttacked(Enemy &e) {
  return e.attack(*this);
}

bool Troll::baseAtk (Enemy & e){
  return  e.onAttacked(*this);
}

bool Troll::baseOnAtk(Enemy & e){
  int damage = ceil((100/(100+ this->getDef()))* e.getAtk());
  this->changeHp(this->getHp()-damage);
  return true;
}

bool Troll::attack(Dragon &e){
  return this->baseAtk(e);
}

bool Troll::onAttacked(Dragon &e){
  return this->baseOnAtk(e);
}

bool Troll::attack(Dwarf &e){
  return this->baseAtk(e);
}

bool Troll::onAttacked(Dwarf &e){
   return this->baseOnAtk(e);
}

bool Troll::attack(Elf &e) {
  return this->baseAtk(e);
}

bool Troll::onAttacked(Elf &e){
   return this->baseOnAtk(e);
}

bool Troll::attack(Halfling &e) {
  return this->baseAtk(e);
}

bool Troll::onAttacked(Halfling &e){
   return this->baseOnAtk(e);
}

bool Troll::attack(Human &e){
  return this->baseAtk(e);
}

bool Troll::onAttacked(Human &e){
   return this->baseOnAtk(e);
}

bool Troll::attack(Merchant &e) {
  return this->baseAtk(e);
}

bool Troll::onAttacked(Merchant &e){
  return this->baseOnAtk(e);
}

bool Troll::attack(Orc &e) {
  return this->baseAtk(e);
}

bool Troll::onAttacked(Orc &e){
  return this->baseOnAtk(e);
}


