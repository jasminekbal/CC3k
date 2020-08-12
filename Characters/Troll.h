#ifndef TROLL_H
#define TROLL_H
#include "Player.h"


class Troll: public Player{
    private:
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);

    
    public:
    Troll();
    virtual ~Troll();
    virtual bool attack(Dragon &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Dragon &e) override;
    virtual bool attack(Dwarf &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Dwarf &e) override;
    virtual bool attack(Elf &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Elf &e) override;
    virtual bool attack(Halfling &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Halfling &e) override;
    virtual bool attack(Human &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Human &e) override;
    virtual bool attack(Merchant &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Merchant &e) override;
    virtual bool attack(Orc &e) override;  //might return a string if we want to go that route
    virtual bool onAttacked(Orc &e) override;

};

#endif

