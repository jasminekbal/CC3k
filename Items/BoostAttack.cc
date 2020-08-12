#include "BoostAttack.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"



BoostAtk::BoostAtk(): Potion(5){}
BoostAtk::~BoostAtk() {

}

void BoostAtk::usePotion(std::shared_ptr<Player> p){
    this->changeVal('a', p->getAtk()+5, p);
}
void BoostAtk::usePotion( std::shared_ptr<Drow> d){
    this->changeVal('a', d->getAtk()+7, d);
}
    