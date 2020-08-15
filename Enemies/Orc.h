#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class Orc: public Enemy{
    private:
    std::shared_ptr<Gold> gold;

    public:
    Orc();
    virtual ~Orc();
    
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;
};

#endif
