#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include <string>
#include <memory>
#include "Potion.h"

class Player;
class BoostAtk: public Potion {
    private:
    std::string message = "HP increased by 10";

    public:
    BoostAtk();
    virtual ~BoostAtk();
    void usePotion(std::shared_ptr<Player> p); 
    void usePotion(std::shared_ptr<Drow> d); 
    std::string getMessage();
};

#endif
