#ifndef TILE_H
#define TILE_H
#include "Info.h"
#include <memory>
#include <vector>
#include <string>

class Floor;
class Tile{

  protected:
  char c;
  State type;
  //protected so that the ground tiles can access.
  int row;
  int col;

  public:
  Tile(int row, int col, State t);
  virtual ~Tile();
  virtual void notify(){}   // need to override for Ground
  // need this function since Floor calls notify() on each tile in its vector
  virtual std::string moveEnemy() { return "";} // overrided for Ground
  virtual std::string movePlayer(int dir){ return "";}
  char getChar();
  Info getInfo();
  virtual void clear();
  friend class Floor;

};

#endif
