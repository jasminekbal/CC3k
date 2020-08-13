#include "PoisonHealth.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


PoisonHP::PoisonHP(): Potion(-10, "PH") {}

PoisonHP::~PoisonHP(){
}

void PoisonHP::usePotion(std::shared_ptr<Player> p){
    if (p->getType() =='D'){
        this->changeVal('h', p->getHp()-15, p);
    } else {
        this->changeVal('h', p->getHp()-10, p);
    }  
} 
