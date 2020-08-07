#ifndef _INFO_H
#define _INFO_H
#include <cstddef> // defines size_t i.e. an unsigned int

// State of the cell i.e.
enum class State { Whitespace, Ground, Passageway, HorizontalWall, VerticalWall, Door, Stairs, Enemy, Player, Potion, Gold };

// Information for the cell to return
struct Info {
    State state;
    int row, col;
};

#endif
