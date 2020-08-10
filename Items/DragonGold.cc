#include "DragonGold.h"
#include "../Enemies/Dragon.h"
#include "../Characters/Player.h"

DragonGold:: DragonGold(): Gold(6, false){

}

DragonGold::~DragonGold(){

}

void DragonGold::setDragon(std::shared_ptr<Dragon> d) {
    dragon = d;
}
    
void DragonGold::attack(Player &p){
    p.onAttacked(*dragon);
}

