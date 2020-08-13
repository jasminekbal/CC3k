#include "WoundDefence.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"


WoundDef::WoundDef(): Potion(-5) {}

WoundDef::~WoundDef(){

}

void WoundDef::usePotion(std::shared_ptr<Player> p){
    this->changeVal('d', p->getDef()-5, p);
} 

void WoundDef::usePotion( std::shared_ptr<Drow> d){
     this->changeVal('d', d->getDef()-7, d);
}
