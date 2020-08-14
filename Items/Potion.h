#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include "../Characters/Player.h"
#include <string>
#include <memory>

class Player;
class Drow;

class Potion: public Item{
    protected:
    std::string type;

    public:
    Potion(int change, std::string type): Item(change, 'P'), type{type}{}
    virtual void usePotion( std::shared_ptr<Player> p) = 0; 
    void changeVal(char c, int val, std::shared_ptr<Player> p ){
        if (c=='a') {
            p->changeAtk(val);
        } else if (c=='d') {
            p->changeDef(val);
        } else {
            p->changeHp(val);
        }
    }
    std::string getType(){
        return type;
    }

};

#endif
