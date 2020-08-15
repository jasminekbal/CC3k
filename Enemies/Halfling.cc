#include "Halfling.h"
#include "../Characters/Player.h"
#include "../Items/DragonGold.h"
#include "../Characters/Player.h"
#include "../Characters/Drow.h"
#include "../Characters/Goblin.h"
#include "../Characters/Vampire.h"
#include "../Characters/Shade.h"
#include "../Characters/Troll.h"
#include <cmath>

Halfling::Halfling():Enemy(100, 15, 20, 'L'){
    auto newG = std::make_shared<Gold>(2, true);
    this->setGold(newG);
}

Halfling::~Halfling(){
   
}

bool Halfling::onAttacked(Player & p){
    bool goesThrough = this->randAtk();
    if (goesThrough){
        double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) p.getAtk());
        int damage = (int) floor( tempDamage );
        setHP(this->getHp() - damage);
        return true;
    }
    return false;
}

void Halfling::setGold(std::shared_ptr<Gold> g){
    gold = g;
}

std::shared_ptr<Gold> Halfling::onDeath(){
    return gold;
}
