#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <string>
#include <iostream>
#include <stdio>
#include <iostream>

using namespace std;

class Floor{
  private:
    vector<shared_ptr<Tile>> tiles;
    private void spawnEnemies();
    private void spawnItems();

  public:
    Floor();
    Floor(istream in);
    void print();
    int movePlayer(); // return 0 for failed
    void moveEnemy();
    int checkPlayerState(); // 0 for normal, 1 if player got to stairs, 2 if player died

}

#endif
