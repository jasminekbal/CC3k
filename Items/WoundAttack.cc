#include "WoundAttack.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


WoundAtk::WoundAtk(): Potion(-5) {}

WoundAtk::~WoundAtk(){

}

void WoundAtk::usePotion(std::shared_ptr<Player> p){
    if (p->getType()=='D'){
        this->changeVal('a', p->getAtk()-7, p);
    } else{
        this->changeVal('a', p->getAtk()-5, p);
    }
    
} 


