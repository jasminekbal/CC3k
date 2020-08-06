#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Info.h"

class Observer;

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;

  public:
    void attach(Observer *o);
    void notifyObservers();
    virtual Info getInfo() const = 0;
};

#endif
