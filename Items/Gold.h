#ifndef GOLD_H
#define GOLD_H
#include "Item.h"

class Player;
class Human;

class Gold: public Item{
  private:
    bool canCollect; // no for dragons (also merchant and human gold if you’re not standing on it)
    void changeVal(int val);

  public:
    Gold(int val, bool can);
    virtual ~Gold();
    void setCanCollect(bool can);
    bool getCanCollect();
};

#endif
