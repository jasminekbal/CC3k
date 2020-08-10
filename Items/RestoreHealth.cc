#include "RestoreHealth.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


RestoreHp::RestoreHp(): Potion(10,"Increase health by upto 10pts") {}

RestoreHp::~RestoreHp(){

}

void RestoreHp::usePotion(std::shared_ptr<Player> p){
    this->changeVal('h', p->getHp()+10, p);
} 

void RestoreHp::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('h', d->getHp()+15, d);
}

