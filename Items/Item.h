#ifndef ITEM_H
#define ITEM_H

class Item{
    protected:
    int change;
    char c;

    public: 
    Item(int change, char c): change{change}, c{c}{}
    virtual ~Item() = 0;
    int getChange(){
        return change;
    }
    char getChar(){
        return c;
    }
};

#endif
