#ifndef FLOOR_H
#define FLOOR_H
#include "Info.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Subject;
class Observer;
class Tile;
class Ground;
class TextDisplay;
class Enemy;
class Potion;
class Gold;
class DragonGold;
class Player;
class Dragon;
class RandomGeneration;

class Floor{
  private:
    std::string message;
    
    //fields
    std::vector<std::vector<std::shared_ptr<Tile> > > tiles;
    std::shared_ptr<Ground> player;

    //typing from input
    std::shared_ptr<Potion> getPotion( char c );
    std::shared_ptr<Gold> getGold( char c );
    std::shared_ptr<Enemy> getEnemy( char c );
    std::shared_ptr<Ground> getGround( int row, int col, char c, State & t );
    std::shared_ptr<Dragon> getDragon( int row, int col );

    //constructor helper functions 
    void checkDragonGold();
    void addTile( int row, int col, char c, std::shared_ptr<Player> p );
    void addNeighbours( Ground & s, int row, int col );
    void attachObservers(std::shared_ptr<TextDisplay> td );
  
    //random generation helper functions 
    void getChamber(int & chamIndex, RandomGeneration & rng, int & NUM_CHAMBERS, const int player );

    std::shared_ptr<Ground> generateLocation( int & chamIndex, int & tileIndex, std::vector<std::vector<std::shared_ptr<Ground> > > & chambers,
    RandomGeneration & rng, int & NUM_CHAMBERS, int player = -1 );

    void removeTile( int & chamIndex, int & tileIndex, std::vector<std::vector<std::shared_ptr<Ground> > > & chambers );
    

    std::shared_ptr<Ground> randomDragon( std::shared_ptr<DragonGold> dg, std::shared_ptr<Ground> tile, RandomGeneration & rng );
    void removeDragonTile(int & chamIndex, std::vector<std::vector<std::shared_ptr<Ground> > > & chambers, std::shared_ptr<Ground> DragonTile );
    //int getRow(int index);
    //int getCol(int index);

    void notify(); // calls notify on all the tiles

  public:

    Floor( std::shared_ptr<TextDisplay> td, std::istream & in, std::shared_ptr<Player> p );
    ~Floor();
    void setPlayerPointer(std::shared_ptr<Player> p );
    void generate( std::shared_ptr<Player> p ); // randomly generates the enemies and gold and potions. 
    std::string moveEnemies();

};



#endif
