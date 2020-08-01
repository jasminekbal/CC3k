#ifndef GROUND_H
#define GROUND_H
#include "info.h"
using namespace std;

class Ground: Tile, Subject, Observer{
  private:
    State type;
    int chamber;
    vector<shared_ptr<Tile>> neighbours;
    TextDisplay * td;

    //Player * p = nullptr;
    //Enemy * e = nullptr;
    Potion * p = nullptr;
    Gold * g = nullptr;

  public:
    Ground(int roomNum);
    void operator=(Ground && tile); // move contents of t to this Tile   // make it error if it doesn't work
    void empty(); // empty this tile of contents, set type to 1
}

#endif
