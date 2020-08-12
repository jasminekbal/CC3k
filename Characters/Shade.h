#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade: public Player {
    private:
    bool baseAtk (Enemy & e);
    bool baseOnAtk(Enemy & e);

    public:
    Shade();
    virtual ~Shade();
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
    int getScore() const; //50% more
};

#endif

