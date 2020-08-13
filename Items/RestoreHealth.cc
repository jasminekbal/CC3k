#include "RestoreHealth.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


RestoreHP::RestoreHP(): Potion(10, "RH") {}

RestoreHP::~RestoreHP(){

}

void RestoreHP::usePotion(std::shared_ptr<Player> p){
    if (p->getType()=='D'){
        this->changeVal('h', p->getHp()+15, p);
    } else {
        this->changeVal('h', p->getHp()+10, p);
    }
} 

