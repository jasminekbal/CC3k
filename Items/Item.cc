#include "Item.h"


Item::Item(int change, char c): change{change}, c{c}{}

Item::~Item(){}

int Item::getChange(){
        return change;
    }

char Item::getChar(){
        return c;
}
