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
  virtual ~Tile();
  virtual void notify();   // need to override for Ground
  // need this function since Floor calls notify() on each tile in its vector
  char getChar();
  Info getInfo();

};

#endif
