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

Vampire::Vampire(): Player(50, 25, 25, -1, 'V'){}

Vampire::~Vampire(){
}

bool Vampire::attack(Enemy * e) {
  bool goesThrough = e->onAttacked(*this);
  if (goesThrough){
    if (e->getChar()=='W'){
      this->changeHp(this->getHp()-5);
    }else {
      this->changeHp(this->getHp()+5);
    }
  }
  return goesThrough;
}
