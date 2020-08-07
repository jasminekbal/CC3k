#ifndef TILE_H
#define TILE_H
#include "Info.h"
#include <memory>
#include <vector>


class Tile{

  protected:
  char c;
  State type;
  //protected so that the ground tiles can access.
  int row;
  int col;
  
  public:
  Tile(int r, int c, State t);
  char getChar();
  Info getInfo();

};

#endif
