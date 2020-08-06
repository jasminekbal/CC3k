#ifndef READ_FILE_H
#define READ_FILE_H
#include <memory>
#include <iostream>

class Floor; 
class TextDisplay;
class Tile;
class Player;
class Potion;
class Enemy;
class Gold;
class Ground;

void makeFloor( Floor & f ); //default version

void makeFloor( Floor & f, std::shared_ptr<Player> p, std::istream & in ); //from file


#endif
