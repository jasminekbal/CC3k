#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <memory>

class Tile;
class Ground;
class Observer {
  public:
    // Pass the Subject that called the notify method.
    virtual void notify( Tile & whoNotified );
    virtual void notify( std::shared_ptr<Ground> whoNotified );
    virtual void notify() = 0;
    virtual ~Observer() = default;
};

#endif
