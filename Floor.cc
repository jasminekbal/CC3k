#include "Floor.h"
#include "Tile.h"
#include <vector>
#include <string>
#include <iostream>

// call notify() for each tile
void Floor::notify(){
  for (auto x : tiles){
    for (auto y : x){
      y->notify();
    }
  }
}

// try to move enemy to a random tile or attack
// a player tile if there is one near it
void Floor::moveEnemies(){
  for (auto x : tiles){
    for (auto y : x){
      y->moveEnemy();
    }
  }
}

