#ifndef RANDOM_GEN_POTION_H
#define RANDOM_GEN_POTION_H
#include <memory>
#include "RandomGeneration.h"

class Potion;

class RandomPotion: public RandomGeneration{

    int rh, ba, bd, ph, wa, wd; //these store the probabilities. 
    public:
    RandomPotion( int rh, int ba, int bd, int ph, int wa, int wd ); //can be used for location and for determining type
    std::shared_ptr<Potion> getPotion();
    
};

#endif

