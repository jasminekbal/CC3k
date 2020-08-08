#include "Elf.h"

Elf::Elf():Enemy(140, 30, 10, 'E'){}

Elf::~Elf(){}


//will do later
bool Elf::attack(Player &p){
    return false;
}

bool Elf::onAttacked(Player &p){
    return false;
}

bool Elf::onAttacked(Drow &d){
    return false;
}
