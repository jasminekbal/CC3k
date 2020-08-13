#include "Shade.h"
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

Shade::Shade(): Player(125, 25, 25, 125, 'S'){
}

Shade::~Shade(){

}

bool Shade::onAttacked(Enemy &e) {
  return e.attack(*this);
}


bool Shade::baseAtk (Enemy & e){
  return e.onAttacked(*this);
}

bool Shade::baseOnAtk(Enemy & e){
  double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) e.getAtk());
  int damage = (int) floor( tempDamage );
  this->changeHp(this->getHp()-damage);
  return true;
}

bool Shade::attack(Dragon &e){
  return this->baseAtk(e);
}

bool Shade::onAttacked(Dragon &e){
  return this->baseOnAtk(e);
}

bool Shade::attack(Dwarf &e){
  return this->baseAtk(e);
}

bool Shade::onAttacked(Dwarf &e){
   return this->baseOnAtk(e);
}

bool Shade::attack(Elf &e) {
  return this->baseAtk(e);
}

bool Shade::onAttacked(Elf &e){
   return this->baseOnAtk(e);
}

bool Shade::attack(Halfling &e) {
  return this->baseAtk(e);
}

bool Shade::onAttacked(Halfling &e){
   return this->baseOnAtk(e);
}

bool Shade::attack(Human &e){
  return this->baseAtk(e);
}

bool Shade::onAttacked(Human &e){
   return this->baseOnAtk(e);
}

bool Shade::attack(Merchant &e) {
  return this->baseAtk(e);
}

bool Shade::onAttacked(Merchant &e){
  return this->baseOnAtk(e);
}

bool Shade::attack(Orc &e) {
  return this->baseAtk(e);
}

bool Shade::onAttacked(Orc &e){
  return this->baseOnAtk(e);
}

int Shade::getScore() const{
    return this->Player::getScore() + this->Player::getScore()/2;
}

