#include "BoostAttack.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"



BoostAtk::BoostAtk(): Potion(5, "BA"){}
BoostAtk::~BoostAtk() {

}

void BoostAtk::usePotion(std::shared_ptr<Player> p){
   if (p->getType()=='D'){
       this->changeVal('a', p->getAtk()+7, p);
   } else {
       this->changeVal('a', p->getAtk()+5, p);
   }
}

