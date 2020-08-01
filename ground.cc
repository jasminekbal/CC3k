#include "ground.h"
#include "observer.h"
#include "subject.h"
#include "tile.h"


int Ground::operator=(Tile && t){ // move contents of t to this Tile
  // return 1 if successful, 0 otherwise (when there's something already there or a wall)

}

void Ground::empty(){ // empty this tile of contents, set type to 1

}
