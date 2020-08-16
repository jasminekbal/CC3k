#ifndef RANDOM_GEN_ENEMY_H
#define RANDOM_GEN_ENEMY_H
#include <memory>
#include "RandomGeneration.h"

class Enemy;

class RandomEnemy: public RandomGeneration{
    //int count = 0;
    int h, w, e, o, m, l; //these store the probabilities. 
    public:
    RandomEnemy( int h, int w, int e, int o, int m, int l ); //can be used for location and for determining type
    std::shared_ptr<Enemy> get();
    //int getCount(){return count;}
};


#endif
