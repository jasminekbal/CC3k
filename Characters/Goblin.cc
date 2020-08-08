#include <memory>
#include "Goblin.h"

using namespace std;


Goblin::Goblin(): Player( 110, 15, 20, 110 ) {}
Goblin::~Goblin(){

}

// will do later
bool Goblin::attack(Enemy &e);

bool Goblin::onAttacked(Enemy &e);
