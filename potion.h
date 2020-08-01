#ifndef POTION_H
#define POTION_H
using namespace std;

class Potion{
  private:
    string type;
  public:
    Potion(string name){
      type=name;
    }
    virtual usePotion();
}

#endif
