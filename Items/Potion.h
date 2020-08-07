#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include <string>
#include <memory>

class Player;
class Drow;

class Potion: public Item{
    protected:
    std::string message;

    public:
    Potion(int change, std::string m): Item(change){ message = m; }
    virtual void usePotion( std::shared_ptr<Player> p) = 0; 
    virtual void usePotion( std::shared_ptr<Drow> d) = 0;
};

#endif
