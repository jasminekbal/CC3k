#ifndef DRAGONGOLD_H
#define DRAGONGOLD_H
#include "Gold.h"
#include <memory>

class Dragon;

class DragonGold: public Gold{
  private:
    std::shared_ptr<Dragon> d;

  public:
    DragonGold();
};

#endif
