#include "WoundAttack.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


WoundAtk::WoundAtk(): Potion(-5) {}

WoundAtk::~WoundAtk(){

}

void WoundAtk::usePotion(std::shared_ptr<Player> p){
    this->changeVal('a', p->getAtk()-5, p);
} 

void WoundAtk::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('a', d->getAtk()-7, d);
}

