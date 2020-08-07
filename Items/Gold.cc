#include "Gold.h"
using namespace std;

Gold::Gold(int val, bool can): Item(val){ canCollect = can; }

void Gold::setCanCollect(bool can){ canCollect = can; }

void Gold::collectGold(Player & p){}

