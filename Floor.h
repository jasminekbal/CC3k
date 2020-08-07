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
class Player;

class Floor{
  private:
    std::vector<std::vector<std::shared_ptr<Tile> > > tiles;
    void spawnEnemies();
    void spawnItems();
    void spawnStairs();

    void addTile( int row, int col, char c, std::shared_ptr<Player> p );
    void addDefaultTile( int row, int col, char c );

    void attachObservers(std::shared_ptr<TextDisplay> td );
    void addNeighbours( Subject & s, int row, int col );
    void addTextDisplay( Subject & s, std::shared_ptr<TextDisplay> td );

    int randomInt(int low, int high);
    int getRow(int index);
    int getCol(int index);

    std::shared_ptr<Enemy> getEnemy( char c );
    std::shared_ptr<Potion> getPotion( char c );
    std::shared_ptr<Gold> getGold( char c );

    std::shared_ptr<Ground> getGround( int row, int col, char c, State & t );
    std::shared_ptr<Ground> getDefaultGround( int row, int col, char c );

  public:

    Floor( std::shared_ptr<TextDisplay> td );
    Floor( std::shared_ptr<TextDisplay> td, std::istream & in, std::shared_ptr<Player> );

    //functions for tick 
    void calculate(); // this makes the tiles calculate their booleans according to what pointer is on them
    void notify(); // calls notify on all the tiles

    void print();
    void clear(); //clears the enemies and potions and gold and stairs
    
    void generate( std::shared_ptr<Player> ); // randomly generates the enemies and gold and potions. 
    
    void moveChar(int dir);
    void moveEnemies();
    void attack(int row, int col, int dir);
    std::string usePotion(int row, int col, int dir);

};




#endif