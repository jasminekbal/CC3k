#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "Observer.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>

class Subject;
class Ground;
class TextDisplay: public Observer{
    private:
    int rows;
    int cols;
    std::vector<std::vector<char>> display;

    public:
    TextDisplay(int numRows = 15, int numCols = 79);
    void notify( Tile & whoNotified );  // overload
    void notify() override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream & operator<<(std::ostream & out, const TextDisplay & td);

#endif
