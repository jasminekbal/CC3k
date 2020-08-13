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
    std::string message;
    int rows;
    int cols;
    std::vector<std::vector<char>> display;

    public:
    TextDisplay();
    void notify( std::shared_ptr<Tile> whoNotified ) override;  // overload
    void notify() override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream & operator<<(std::ostream & out, const TextDisplay & td);

#endif
