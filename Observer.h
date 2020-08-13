#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Tile;

class Observer {
  public:
    // Pass the Subject that called the notify method.
    void notify( Tile & whoNotified );
    virtual void notify( shared_ptr<Ground> whoNotified );
    virtual void notify() = 0;
    virtual ~Observer() = default;
};

#endif
