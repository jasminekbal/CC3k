#include "RestoreHealth.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


RestoreHP::RestoreHP(): Potion(10) {}

RestoreHP::~RestoreHP(){

}

void RestoreHP::usePotion(std::shared_ptr<Player> p){
    this->changeVal('h', p->getHp()+10, p);
} 

void RestoreHP::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('h', d->getHp()+15, d);
}

