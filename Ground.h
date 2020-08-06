#ifndef GROUND_H
#define GROUND_H
#include "Info.h"
#include "Tile.h"
#include "Subject.h"
#include "Observer.h"

class Player;
class Enemy;
class Potion;
class Gold;
class Ground: Tile, Subject, Observer{
  private:
    int chamber;
    bool isStair;
    bool hasObject;
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<Enemy> enemy = nullptr;
    std::shared_ptr<Potion> potion = nullptr;
    std::shared_ptr<Gold> gold = nullptr;
    

  public:
    Ground( int row, int col, int chamber = 0 );
    void operator=(Ground && tile); // move contents of tile to this Tile   // make it error if it doesn't work
    void empty(); // empty this tile of contents, set type to 1
    bool getIsStair();

    friend class Floor;
};

#endif
