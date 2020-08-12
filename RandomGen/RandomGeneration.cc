#include "RandomGeneration.h"
#include <ctime>
#include <iostream>

RandomGeneration::~RandomGeneration(){}

int RandomGeneration::setSeed(){
    std::srand( (unsigned) std::time( 0 ) );
}

int RandomGeneration::randomInt( int high, int low ){
    int range = high - low;
    if( range == 0 ){
        return low;
    }
    int randNum = ( std::rand() % range) + low;
    return randNum;
}

