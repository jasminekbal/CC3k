#include "WoundAttack.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


WoundAtk::WoundAtk(): Potion(-5,"Decrease attack by 5pts") {}

WoundAtk::~WoundAtk(){

}

void WoundAtk::usePotion(std::shared_ptr<Player> p){
    this->changeVal('a', p->getHp()-5, p);
} 

void WoundAtk::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('a', d->getHp()-7, d);
}

