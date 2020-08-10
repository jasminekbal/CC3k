#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class Drow;

class RestoreHp: public Potion {
    
    public:
    RestoreHp();
    virtual ~RestoreHp();
    void usePotion(std::shared_ptr<Player> p); 
    void usePotion(std::shared_ptr<Drow> d); 
};

#endif
