#include "Gold.h"

Gold::Gold(int val, bool can): Item(val, can){}

void Gold::setCanCollect(bool can){
  canCollect = can;
}

