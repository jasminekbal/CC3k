#include "Info.h"
#include "Tile.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

Tile::Tile(int row, int col, State t): type{t}, row{row}, col{col}  {
    //  Whitespace = ' ', HorizontalWall = '-', 
    // VerticalWall='|', Door = '+'
    if (type == State::Whitespace){
        c=' ';
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
}

Tile::~Tile() {}

char Tile::getChar(){
    //cout << "@ Tile getChar(): " << c << endl;
    return c;
}

Info Tile::getInfo(){
    Info i;
    i.state = type;
    i.row = row;
    i.col = col;
    return i;
}

void Tile::clear(){}
