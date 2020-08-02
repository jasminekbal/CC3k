#ifndef TILE_H
#define TILE_H
#include "info.h"
using namespace std;

class Tile{
  private:
    State type;
    int chamber;
    vector<shared_ptr<Tile>> neighbours;
    shared_ptr<TextDisplay> td;

    //Player * p = nullptr;
    //Enemy * e = nullptr;
    //Potion * p = nullptr;   // later
    //Gold * g = nullptr;
  
  protected:
  //protected so that the ground tiles can access.
  int row;
  int col;
  
  public:
    Tile(int roomNum);
    Tile(int row, int col);
}

#endif
