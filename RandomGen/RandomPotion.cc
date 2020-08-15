#include "RandomGeneration.h"
#include "RandomPotion.h"
#include "../Items/BoostAttack.h"
#include "../Items/BoostDefence.h"
#include "../Items/PoisonHealth.h"
#include "../Items/RestoreHealth.h"
#include "../Items/WoundAttack.h"
#include "../Items/WoundDefence.h"
#include "../Exceptions.h"

using namespace std;

RandomPotion::RandomPotion( int rh, int ba, int bd, int ph, int wa, int wd )
    : rh{rh}, ba{ba}, bd{bd}, ph{ph}, wa{wa}, wd{wd} {}

std::shared_ptr<Potion> RandomPotion::get(){
    int type = randomInt( rh + ba + bd + ph + wa + wd );
    if( type < rh){
        return make_shared<RestoreHP>();
    }
    if( type < rh + ba ){
        return make_shared<BoostAtk>();
    } 
    if( type < rh + ba + bd ){
        return make_shared<BoostDef>();
    }
    if( type < rh + ba + bd + ph ){
        return make_shared<PoisonHP>();
    }
    if( type < rh + ba + bd + ph + wa ){
        return make_shared<WoundAtk>();
    }
    if( type < rh + ba + bd + ph + wa + wd ){
        return make_shared<WoundDef>();
    } else {
        throw Exceptions( "Not a valid int " );
    }
}


