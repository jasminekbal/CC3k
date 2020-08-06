#ifndef RANDOM_GEN_H
#define RANDOM_GEN_H
#include <cstdlib>

class RandomGeneration{

    public:
    int setSeed(); //call once at the beginning. 

    //includes low, excludes high
    int randomInt(int high, int low = 0); //can be used for location and for determining type
};

#endif
