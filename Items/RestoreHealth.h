#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class Drow;

class RestoreHP: public Potion {
    
    public:
    RestoreHP();
    virtual ~RestoreHP();
    void usePotion(std::shared_ptr<Player> p); 
};

#endif
