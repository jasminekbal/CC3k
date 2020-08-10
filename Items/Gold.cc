#include "Gold.h"

Gold::Gold(int val, bool can): Item(val, 'G'){
  canCollect = can;
}

Gold::~Gold(){

}

bool Gold::getCanCollect(){
  return canCollect;
}

void Gold::setCanCollect(bool can){
  canCollect = can;
}

