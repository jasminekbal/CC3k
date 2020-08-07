#include "Floor.h"
#include "Tile.h"
#include "Ground.h"
#include "Subject.h"
#include "Observer.h"
#include "TextDisplay.h"
#include "Info.h"
#include "Exceptions.h"
#include "Characters/Drow.h"
#include "Characters/Goblin.h"
#include "Characters/Shade.h"
#include "Characters/Troll.h"
#include "Characters/Vampire.h"
#include "Enemies/Dragon.h"
#include "Enemies/Dwarf.h"
#include "Enemies/Elf.h"
#include "Enemies/Halfling.h"
#include "Enemies/Human.h"
#include "Enemies/Merchant.h"
#include "Enemies/Orc.h"
#include "Items/Gold.h"
#include "Items/DragonGold.h"
#include "Items/BoostAttack.h"
#include "Items/BoostDefence.h"
#include "Items/PoisonHealth.h"
#include "Items/RestoreHealth.h"
#include "Items/WoundAttack.h"
#include "Items/WoundDefence.h"
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>

using namespace std;

/*
implementing 

std::shared_ptr<Potion> getPotion( char c );
std::shared_ptr<Gold> getGold( char c );
std::shared_ptr<Enemy> getEnemy( char c );

std::shared_ptr<Ground> getGround( int row, int col, char c );
std::shared_ptr<Ground> getDefaultGround( int row, int col, char c );

and 

void Floor::addTile( int row, int col, char c, std::shared_ptr<Player> p );
void Floor::addDefaultTile( int row, int col, char c );

void Floor::attachObservers(std::shared_ptr<TextDisplay> td );

Floor::Floor( std::shared_ptr<TextDisplay> td );

Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream in );

Floor::addNeighbours( Subject & s );

Still needs to check dragon gold. When reading in, the dragon gold and the dragon are not attached
*/
//beginning of code

shared_ptr<Potion> Floor::getPotion( char c ){
    shared_ptr<Potion> potion;
    switch( c ){
        case '0':
            potion = make_shared<RestoreHP>();
            break;
        case '1':
            potion = make_shared<BoostAtk>();
            break;
        case '2':
            potion = make_shared<BoostDef>();
            break;
        case '3':
            potion = make_shared<PoisonHP>();
            break;
        case '4':
            potion = make_shared<WoundAtk>();
            break;
        case '5':
            potion = make_shared<WoundDef>();
            break;
    }
    return potion;
}

std::shared_ptr<Gold> Floor::getGold( char c ){
    std::shared_ptr<Gold> gold;
    int value;
    switch( c ){
        case '6':
            value = 2;
            break;
        case '7':
            value = 1;
            break;
        case '8':
            value = 4;
            break;
    }
    gold = make_shared<Gold>(value);
    return gold;
}

std::shared_ptr<Enemy> Floor::getEnemy( char c ){
    std::shared_ptr<Enemy> enemy;
    switch( c ){
        case 'H':
            enemy = make_shared<Human>();
        case 'W':
            enemy = make_shared<Dwarf>();
        case 'E':
            enemy = make_shared<Elf>();
        case 'O':
            enemy = make_shared<Orc>();
        case 'M':
            enemy = make_shared<Merchant>();
        case 'D':
            enemy = make_shared<Dragon>();
        case 'L':
            enemy = make_shared<Halfling>();
    }
    return enemy;
}

std::shared_ptr<Ground> Floor::getGround(int row, int col, char c, State & t){
    std::shared_ptr<Potion> potion = nullptr;
    std::shared_ptr<Gold> gold = nullptr;
    std::shared_ptr<Enemy> enemy = nullptr;
    int chamber = -1;
    switch( c ){
        case '\\':
            t = State::Stairs;
            break;
        case '.':
            t = State::Ground;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            t = State::Potion;
            potion = getPotion( c );
            break;
        case '6':
        case '7':
        case '8':
            t = State::Gold;
            gold = getGold( c );
            break;
        case '9': {
            t = State::Gold;
            int value = 6;
            gold = make_shared<DragonGold>( value );
            break;
        }
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D': 
        case 'L': 
            t = State::Enemy;
            enemy = getEnemy( c );
            break;
        default:
            throw noFile( "not a permitted character");
    }
    return make_shared<Ground>( row, col, t, chamber, enemy, potion, gold );
}


std::shared_ptr<Ground> Floor::getDefaultGround(int row, int col, char c ){
    State t = State::Ground;
    int chamber = c - 'a';
    c = '.'; 
    return make_shared<Ground>(row, col, t, chamber );
}

void Floor::addTile( int row, int col, char c, std::shared_ptr<Player> p ){
    std::shared_ptr<Tile> tile = nullptr;
    std::shared_ptr<Ground> ground = nullptr;
    State t;
    int chamber = -1;
    switch( c ){
        case '|':
            t = State::VerticalWall;
            tile = make_shared<Tile>(row, col, t);
            break;
        case '-':
            t = State::HorizontalWall;
            tile = make_shared<Tile>(row, col, t);
            break;
        case ' ':
            t = State::Whitespace;
            tile = make_shared<Tile>(row, col, t);
            break;
        case '@':
            t = State::Player;
            ground = make_shared<Ground>(row, col, t, -1, nullptr, nullptr, nullptr, p);
            p->setLocation( ground ); //players need a way to set location
            break;
        case '+':
            t = State::Door;
            ground = make_shared<Ground>( row, col, t, chamber );
            break;
        case '#':
            t = State::Passageway;
            ground = make_shared<Ground>( row, col, t, chamber );
            break;
        default:
            if( p == nullptr){
                ground = getDefaultGround(row, col, c );
            } else {
                ground = getGround( row, col, c, t );
            }
            break;
    }
    if( tile != nullptr ){
        tiles[row].push_back( tile );
    }
    else{
        tiles[row].push_back( ground );
    }
}


void Floor::addNeighbours( Subject & currentSubject, int row, int col ) {
    int i, j;
    for( i = row - 1 ; i < row + 2; i ++ ){
        for( j = col - 1 ; j < col + 2; j++ ){
            shared_ptr<Observer> neighbour = dynamic_pointer_cast< Ground > ( tiles[i][j] );
            currentSubject.attach( neighbour );
        }
    }
}

void Floor::attachObservers( std::shared_ptr<TextDisplay> td ){
    int row = 0;
    int col = 0;
    for( auto r : tiles){
        for( auto tile : r ){
            shared_ptr<Ground> groundTile = dynamic_pointer_cast< Ground >(tile);
            if( groundTile != nullptr ){
                addNeighbours( * groundTile, row, col );
                groundTile->attach( td );
            } else {
                td->notify( * tile );
            }
            col++;
        }
        row++;
    }
}

Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream & in, std::shared_ptr<Player> p = nullptr ) {

    string line;
    char c;
    int row;
    int col;

    for( int i = 0; i < 25; i++ ){
        row = i;
        col = 0;
        vector<shared_ptr<Tile> > t;
        tiles.push_back(t);
        getline( in, line );
        istringstream input{ line };

        while( input >> c ){
            addTile( row, col, c, p );
            col++;
        }

    }

    this->attachObservers( td );
}

