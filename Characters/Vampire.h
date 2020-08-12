#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Dwarf;

class Vampire: public Player {
    private:
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);

    public:
    Vampire();
    virtual ~Vampire();
    virtual bool attack(Dragon &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Dragon &e)= 0;
    virtual bool attack(Dwarf &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Dwarf &e)= 0;
    virtual bool attack(Elf &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Elf &e)= 0;
    virtual bool attack(Halfling &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Halfling &e)= 0;
    virtual bool attack(Human &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Human &e)= 0;
    virtual bool attack(Merchant &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Merchant &e)= 0;
    virtual bool attack(Orc &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Orc &e)= 0;

};

#endif

