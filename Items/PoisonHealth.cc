#include "PoisonHealth.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


PoisonHP::PoisonHP(): Potion(-10) {}

PoisonHP::~PoisonHP(){
}

void PoisonHP::usePotion(std::shared_ptr<Player> p){
    this->changeVal('h', p->getHp()-10, p);
} 

void PoisonHP::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('h', d->getHp()-15, d);
}
