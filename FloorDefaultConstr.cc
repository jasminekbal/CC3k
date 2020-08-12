#include "Floor.h"
#include "Tile.h"
#include "Ground.h"
#include "Subject.h"
#include "Observer.h"
#include "TextDisplay.h"
#include "Info.h"
#include "Exceptions.h"
#include "Characters/Player.h"
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>

using namespace std;

/*
implementing 

std::shared_ptr<Ground> Floor::getDefaultGround( int row, int col, char c );

and 

void Floor::addTile( int row, int col, char c, std::shared_ptr<Player> p );

void Floor::attachObservers( std::shared_ptr<TextDisplay> td );

Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream in, std::shared_ptr<Player> p );

Floor::addNeighbours( Subject & s, int row, int col );

*/
//beginning of code


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

//we can change this implementation if it doesn't work out 
void Floor::addNeighbours( Subject & currentSubject, int row, int col ) {
    int i, j;
    for( i = row - 1 ; i < row + 2; i ++ ){
        for( j = col - 1 ; j < col + 2; j++ ){
            if( i == row && j == col){}
            else{
                shared_ptr<Ground> neighbour = dynamic_pointer_cast<Ground> ( tiles[i][j] );
                currentSubject.attach( neighbour );
            }
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
    attachObservers( td );
    if( p != nullptr ){
        checkDragonGold();
    }
}

