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

// try to move player to tile in dir direction
// if it doesnt work, return why
// if it works, change player's location 
// (dependent on what kind of tile player moved to)
void movePlayer(int dir){

}

