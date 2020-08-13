#include <memory>
#include "Goblin.h"
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

using namespace std;


Goblin::Goblin(): Player( 110, 15, 20, 110, 'G') {}
Goblin::~Goblin(){

}

bool Goblin::onAttacked(Enemy &e){
  return e.attack(*this);
}

bool Goblin::baseAtk (Enemy & e){
  bool goesThrough = e.onAttacked(*this);
  if (e.getHp()== 0){
    this->collectGold(std::make_shared<Gold>(5, true));
  }
  return goesThrough;
}

bool Goblin::baseOnAtk(Enemy & e){
  double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) e.getAtk());
  int damage = (int) floor( tempDamage );
  this->changeHp(this->getHp()-damage);
  return true;
}

bool Goblin::attack(Dragon &e){
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Dragon &e){
  return this->baseOnAtk(e);
}

bool Goblin::attack(Dwarf &e){
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Dwarf &e){
   return this->baseOnAtk(e);
}

bool Goblin::attack(Elf &e) {
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Elf &e){
   return this->baseOnAtk(e);
}

bool Goblin::attack(Halfling &e) {
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Halfling &e){
   return this->baseOnAtk(e);
}

bool Goblin::attack(Human &e){
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Human &e){
   return this->baseOnAtk(e);
}

bool Goblin::attack(Merchant &e) {
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Merchant &e){
  return this->baseOnAtk(e);
}

bool Goblin::attack(Orc &e) {
  return this->baseAtk(e);
}

bool Goblin::onAttacked(Orc &e){
  double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) e.getAtk());
  int damage = (int) floor( tempDamage );
  int altered = damage + damage/2;
  this->changeHp(this->getHp()-altered);
  return true;
}


