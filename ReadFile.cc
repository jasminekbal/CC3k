#include "Floor.h"
#include "Tile.h"
#include "Ground.h"
#include "TextDisplay.h"
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

Floor::Floor( std::shared_ptr<TextDisplay> td );

Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream in );

This still needs 

Floor::addNeighbours( Subject & s );
to work 
*/
//beginning of code


std::shared_ptr<Potion> getPotion( char c ){
    std::shared_ptr<Potion> potion;
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

std::shared_ptr<Gold> getGold( char c ){
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

std::shared_ptr<Enemy> getEnemy( char c ){
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

std::shared_ptr<Ground> getGround(int row, int col, char c ){
    std::shared_ptr<Ground> retGround;
    std::shared_ptr<Potion> potion;
    std::shared_ptr<Gold> gold;
    std::shared_ptr<Enemy> enemy;
    switch( c ){
        int chamber;
        case '.':
        case '+':
        case '#':
            retGround = make_shared<Ground>(row, col, c);
            break;
        case '\\':
            retGround = make_shared<Ground>(row, col, c);
            retGround->setIsStair( true );
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            potion = getPotion( c );
            c = 'P';
            retGround = make_shared<Ground>(row, col, c);
            break;
        case '6':
        case '7':
        case '8':
            gold = getGold( c );
            c = 'G';
            retGround->setGold( gold );
            break;
        case '9': {
            c = 'G';
            int value = 6;
            gold = make_shared<DragonGold>( value );
            retGround = make_shared<Ground>(row, col, c);
            retGround->setGold( gold );
            break;
        }
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D': 
        case 'L': 
            enemy = getEnemy( c );
            retGround = make_shared<Ground>(row, col, c);
            retGround->setEnemy( enemy );
            break;
        default:
            throw noFile( "not a permitted character");
    }
    return retGround;
}


std::shared_ptr<Ground> getDefaultGround(int row, int col, char c ){
    int chamber = c - 'a';
    c = '.';
    auto retGround = make_shared<Ground>(row, col, c, chamber);
    return retGround;
}

void Floor::addTile( int row, int col, char c, std::shared_ptr<Player> p ){
    std::shared_ptr<Tile> tile = nullptr;
    std::shared_ptr<Ground> ground = nullptr;
    switch( c ){
        case '|':
        case '-':
        case ' ':
            tile = make_shared<Tile>(row, col, c);
            break;
        case '@':
            ground = make_shared<Ground>(row, col, c);
            ground->setPlayer( p );
            p->setLocation( ground );
            break;
        default:
            ground = getGround( row, col, c);
            break;
    }
    if( tile != nullptr ){
        tiles[row].push_back( tile );
    }
    else{
        tiles[row].push_back( ground );
    }
}

void Floor::addDefaultTile( int row, int col, char c ){
    std::shared_ptr<Tile> tile = nullptr;
    std::shared_ptr<Ground> ground = nullptr;
    switch( c ){
        case '|':
        case '-':
        case ' ':
            tile = make_shared<Tile>(row, col, c);
            break;
        default:
            ground = getDefaultGround( row, col, c);
            break;
    }
    if( tile != nullptr ){
        tiles[row].push_back( tile );
    }
    else{
        tiles[row].push_back( ground );
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

Floor::Floor( std::shared_ptr<TextDisplay> td  ) {
    
    ifstream infile{ "default.txt" };
    string line;
    char c;
    int row;
    int col;

    for( int i = 0; i < 25; i++ ){
        row = i;
        col = 0;
        vector<shared_ptr<Tile> > t;
        tiles.push_back(t);
        getline( infile, line );
        istringstream input{ line };

        while( input >> c ){
            addDefaultTile( row, col, c );
            col++;
        }
    }

    this->attachObservers( td );
}

Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream & in, std::shared_ptr<Player> p ) {

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

