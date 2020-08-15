#include "Shade.h"
#include "../Enemies/Dragon.h"
#include "../Enemies/Dwarf.h"
#include "../Enemies/Elf.h"
#include "../Enemies/Halfling.h"
#include "../Enemies/Human.h"
#include "../Enemies/Merchant.h"
#include "../Enemies/Orc.h"
#include "../Enemies/Enemy.h"
#include "../Items/Gold.h"
#include <cmath>

Shade::Shade(): Player(125, 25, 25, 125, 'S'){
}

Shade::~Shade(){

}
int Shade::getScore() const{
    return this->Player::getScore() + this->Player::getScore()/2;
}

