#include "WoundDefence.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


WoundDef::WoundDef(): Potion(-5, "WD") {}

WoundDef::~WoundDef(){

}

void WoundDef::usePotion(std::shared_ptr<Player> p){
    if (p->getType() =='D'){
        this->changeVal('d', p->getDef()-7, p);
    } else{
        this->changeVal('d', p->getDef()-5, p);
    } 
} 

