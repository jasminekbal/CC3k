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
class TextDisplay;
class Ground: public Tile, public Subject, public Observer{
  private:
    int chamber;
    bool isStair;
    bool hasObject;
    std::shared_ptr<Player> player;
    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<Ground> playerNearEnemy; // holds the tile next to the enemy that holds a player
    // if there is one
    std::shared_ptr<Potion> potion;
    std::shared_ptr<Gold> gold;

    // dont know if neighbours being type Ground would work when attaching observers
    std::vector<std::shared_ptr<Ground> > neighbours;

    std::shared_ptr<TextDisplay> td;
    

  public:
    Ground(int r, int c, State t, int room = -1, std::shared_ptr<Enemy> e = nullptr , std::shared_ptr<Potion> po = nullptr, std::shared_ptr<Gold> g = nullptr, std::shared_ptr<Player> pl = nullptr);
    void move(Ground & tile); // move contents of tile to this Tile   // make it error if it doesn't work
    void empty(); // empty this tile of contents, set type to 1
    bool getIsStair();

    // Subject overrides
    virtual Info getInfo() const override; // is this supposed to not be virtual?

    // Observer overrides
    virtual void notify() override;
    void notify( Subject & whoNotified ) override;

    friend class Floor;
};

#endif