#include "floor.h"
#include <vector>
#include <string>
#include <iostream>

void Floor::print(){
  for (auto i = tiles.begin(); i != tiles.end(); i+=1){
    tiles[i]->print();
  }
}

int Floor::movePlayer(){ // return 0 for failed

}

void Floor::moveEnemy(){

}

void Floor::spawnEnemies(){

}

void Floor::spawnItems(){

}

int Floor::checkPlayerState(){ // 0 for normal, 1 if player got to stairs, 2 if player died

}
