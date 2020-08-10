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
    Potion(int change, std::string m): Item(change, 'P'){ message = m; }
    virtual void usePotion( std::shared_ptr<Player> p) = 0; 
    virtual void usePotion( std::shared_ptr<Drow> d) = 0;
    void changeVal(char c, int val, std::shared_ptr<Player> p ){
        if (c=='a') {
            p->changeAtk(val);
        } else if (c=='d') {
            p->changeDef(val);
        } else {
            p->changeHp(val);
        }
    }
};

#endif
