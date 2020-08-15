#include "DragonGold.h"
#include "../Exceptions.h"
#include "../Enemies/Dragon.h"
#include "../Characters/Player.h"

DragonGold:: DragonGold(): Gold(6, false){
    dragon = nullptr;
}

DragonGold::~DragonGold(){

}

void DragonGold::setDragon(std::shared_ptr<Dragon> d) {
    dragon = d;
}

bool DragonGold::attack(Player &p){
    if (rand() % 2 == 1){
        p.onAttacked(*dragon);
        return true;
    }
    return false;
}

