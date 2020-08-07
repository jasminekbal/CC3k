#ifndef GOLD_H
#define GOLD_H
#include "Item.h"

class Player;
class Gold: public Item{
  private:
    bool canCollect; // no for dragons (also merchant and human gold if you’re not standing on it)

  public:
    Gold(int val, bool can);
    virtual ~Gold();
    void collectGold(Player & p);
    void setCanCollect(bool can);
};

#endif