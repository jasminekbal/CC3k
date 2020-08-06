#ifndef ITEM_H
#define ITEM_H

class Item{
    protected:
    int change;
    char c;

    public: 
    Item(int change, char c);
    virtual ~Item() = 0;
    int getChange();
    char getChar();
};

#endif
