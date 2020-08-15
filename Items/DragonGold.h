#ifndef DRAGONGOLD_H
#define DRAGONGOLD_H
#include "Gold.h"
#include <memory>

class Dragon;
class Player;

class DragonGold: public Gold{
  private:
    std::shared_ptr<Dragon> dragon;

  public:
    DragonGold();
    ~DragonGold();
    void setDragon(std::shared_ptr<Dragon> d);
    bool attack(Player &p);
};

#endif
