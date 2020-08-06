#ifndef RANDOM_GEN_POTION_H
#define RANDOM_GEN_POTION_H
#include <memory>
#include "RandomGeneration.h"

class Gold;

class RandomGold: public RandomGeneration{
    
    int small, dragon, normal; //these store the probabilities. 
    public:
    RandomGold( int small, int dragon, int normal); //pass in probabilities to the constructor
    std::shared_ptr<Gold> getGold();
    
};

#endif

