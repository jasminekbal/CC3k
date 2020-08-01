#ifndef GOLD_H
#define GOLD_H
using namespace std;

class Gold{
  private:
    int value;
    boolean canCollect; // no for dragons (also merchant and human gold if you’re not standing on it)
    char c;

  public:
    Gold(int val);
    int getVal();
}

#endif
