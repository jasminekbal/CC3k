#include "RandomGeneration.h"
#include "RandomGold.h"
#include <memory>
#include "../Items/Gold.h"
#include "../Items/DragonGold.h"
#include "../Enemies/Dragon.h"

using namespace std;

RandomGold::RandomGold( int small, int dragon, int normal )
    : small{small}, dragon{dragon}, normal{normal} {}

std::shared_ptr<Gold> RandomGold::getGold(){
    int type = randomInt( small + dragon + normal );
    if( type < small){
        return make_shared<Gold>( 1, true );
    }
    if( type < small + dragon ){
        return make_shared<DragonGold>();
    } 
    if( type < small + dragon + normal  ){
        return make_shared<Gold>(2, true);
    }
}

