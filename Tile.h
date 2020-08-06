#ifndef TILE_H
#define TILE_H
#include "Info.h"
#include <memory>
#include <vector>


class Tile{

  protected:
  State type;
  //protected so that the ground tiles can access.
  int row;
  int col;
  
  public:
  Tile(int row, int col);

};

#endif
