#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <memory>
#include <string>
#include <iostream>

class TextDisplay: public Observer{
    private:
    std::vector<std::vector<char>> display;

    public:
    void notify( Subject & whoNotified ) override;
    void notify() override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
}

std::ostream & operator<<(std::ostream & out, TextDisplay & td);

#endif
