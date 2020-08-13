#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Tile;

class Observer {
  public:
    // Pass the Subject that called the notify method.
    virtual void notify( Tile & whoNotified ) = 0;
    virtual void notify() = 0;
    virtual ~Observer() = default;
};

#endif
