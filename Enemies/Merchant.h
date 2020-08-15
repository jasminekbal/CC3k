#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant: public Enemy{

   private:
    std::shared_ptr<Gold> gold;
    static bool hostile;

   public:
   
   Merchant();
   virtual ~Merchant();
   void setGold(std::shared_ptr<Gold> g);
   virtual std::shared_ptr<Gold> onDeath() override;

   bool isHostile() override;
   void makeHostile() override;
  
};

#endif
