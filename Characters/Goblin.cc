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

bool Goblin::onAttackedOrc(Enemy & e) {
  double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) e.getAtk());
  int damage = (int) floor( tempDamage );
  int altered = damage + damage/2;
  this->changeHp(this->getHp()-altered);
  return true;
}

bool Goblin::attack(Enemy * e) {
  bool goesThrough = e->onAttacked(*this);
  if (e->getHp()== 0){
    this->collectGold(make_shared<Gold>(5, true));
  }
  return goesThrough;
}

bool Goblin::onAttacked( Enemy & e ){
  if( e.getChar() == 'O'){
    return onAttackedOrc( e );
  } else {
    double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) e.getAtk());
    int damage = (int) floor( tempDamage );
    this->changeHp(this->getHp()-damage);
    return true;
  }
}

