#include "BoostDefence.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


BoostDef::BoostDef(): Potion(5) {}

BoostDef::~BoostDef(){

}

void BoostDef::usePotion(std::shared_ptr<Player> p){
    if (p->getType()== 'D'){
        this->changeVal('d', p->getDef()+7, p);
    } else{
        this->changeVal('d', p->getDef()+5, p);
    }  
} 
