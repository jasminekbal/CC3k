#include "BoostDefence.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


BoostDef::BoostDef(): Potion(5) {}

BoostDef::~BoostDef(){

}

void BoostDef::usePotion(std::shared_ptr<Player> p){
    this->changeVal('d', p->getDef()+5, p);
} 

void BoostDef::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('d', d->getDef()+7, d);
}

