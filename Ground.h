#ifndef GROUND_H
#define GROUND_H
#include "Info.h"
#include "Tile.h"
#include "Observer.h"
#include <memory>

class Player;
class Enemy;
class Potion;
class Gold;
class TextDisplay;
class Floor;
class Ground: public Tile, public Observer{
  private:
    int chamber;
    std::shared_ptr<Player> player;
    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<Ground> playerNearEnemy; // holds the tile next to the enemy that holds a player
    // if there is one
    std::shared_ptr<Potion> potion;
    std::shared_ptr<Gold> gold;

    std::vector<std::shared_ptr<Ground> > neighbours;
    std::shared_ptr<TextDisplay> td;

    // helper function for moveEnemy()
    std::string randomMove();

    // helper functions for move
    std::string passageWayHelper(Ground & tile);
    std::string doorHelper(Ground & tile);
    std::string enemyHelper(Ground & tile);
    std::string playerHelper(Ground & tile);

    std::string move(Ground & tile); // move contents of tile to this Tile   // make it error if it doesn't work
    

  public:
    Ground(int r, int c, State t, int room = -1, std::shared_ptr<Enemy> e = nullptr , std::shared_ptr<Potion> po = nullptr, std::shared_ptr<Gold> g = nullptr, std::shared_ptr<Player> pl = nullptr);
    virtual ~Ground();
    void empty(); // empty this tile of contents, set type to 1
    bool getIsStair();

    // Subject overrides
    void attach(std::shared_ptr<Ground> g);
    void attach(std::shared_ptr<TextDisplay> td);
    Info getInfo() const;

    // Observer overrides
    virtual void notify() override;
    virtual void notify( std::shared_ptr<Ground> whoNotified ) override;

    void recalculate();

    // setters
    void setPlayer( std::shared_ptr<Player> p){ player = p; }
    void setEnemy( std::shared_ptr<Enemy> e){ enemy = e; }
    void setPotion( std::shared_ptr<Potion> p){ potion = p; }
    void setGold( std::shared_ptr<Gold> g){ gold = g; }
    void setStair( bool b );

    //getter
    std::vector<std::shared_ptr<Ground> > getNeighbours();

    // moves enemy if there's an enemy on this tile
    // called in Floor
    std::string movePlayer(int dir) override;
    std::string moveEnemy() override;

    // getters
    std::shared_ptr<Enemy> getEnemy(){
      return enemy;
    }
    std::shared_ptr<Gold> getGold(){
      return gold;
    }
    int getChamber(){ return chamber; }

    friend class Floor;
};

#endif
