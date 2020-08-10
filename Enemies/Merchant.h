#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant: Enemy{

   private:
   static bool isHostile;

   public:
   Merchant();
   virtual ~Merchant();
   virtual bool attack(Player &p) override;
   virtual bool onAttacked(Player &p) override;
   bool hostile();
   void makeHostile();
  
};

#endif
