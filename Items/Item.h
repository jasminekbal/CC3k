#ifndef ITEM_H
#define ITEM_H

class Item{
    protected:
    int change;
    char c;

    public: 
    Item(int change): change(change){}
    virtual ~Item() = 0;
    int getChange(){ return change; }
};

#endif
