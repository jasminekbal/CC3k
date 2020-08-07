#include "Info.h"
#include "Tile.h"
#include <memory>
#include <vector>

Tile::Tile(int r, int c, State t){
    row = r;
    col = c;
    type = t;
    //  Whitespace = ' ', Passageway = '#', HorizontalWall = '-', 
    // VerticalWall='|', Door = '+', Stairs = '\'
    if (type == State::Whitespace){
        c=' ';
    }
    else if (type == State::Passageway){
        c='#';
    }
    else if (type == State::HorizontalWall){
        c='-';
    }
    else if (type == State::VerticalWall){
        c='|';
    }
    else if (type == State::Door){
        c='+';
    }
    else if (type == State::Stairs){
        c='\'';
    }
}

char Tile::getChar(){
    return c;
}

Info Tile::getInfo(){
    Info i;
    i.state = type;
    i.row = row;
    i.col = col;
    return i;
}