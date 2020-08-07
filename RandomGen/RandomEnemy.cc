#include <memory>
#include "RandomEnemy.h"
#include "../Enemies/Enemy.h"
#include "../Enemies/Dwarf.h"
#include "../Enemies/Elf.h"
#include "../Enemies/Halfling.h"
#include "../Enemies/Human.h"
#include "../Enemies/Merchant.h"
#include "../Enemies/Orc.h"

using namespace std;

RandomEnemy::RandomEnemy( int h, int w, int e, int o, int m, int l )
    : h{h}, w{w}, e{e}, o{o}, m{m}, l{l} {}

std::shared_ptr<Enemy> RandomEnemy::getEnemy(){
    int type = randomInt( l + m + o + e + w + h );
    if( type < h){
        return make_shared<Human>();
    }
    if( type < h + w){
        return make_shared<Dwarf>();
    } 
    if( type < e + w + h ){
        return make_shared<Elf>();
    }
    if( type < o + e + w + h ){
        return make_shared<Orc>();
    }
    if( type < m + o + e + w + h ){
        return make_shared<Merchant>();
    }
    if( type < l + o + e + w + h ){
        return make_shared<Halfling>();
    }
}



