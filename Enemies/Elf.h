#ifndef ELF_H
#define ELF_H
#include "Enemy.h"

class Drow;

class Elf: public Enemy{
    std::shared_ptr<Gold> gold;

    public:
    Elf();
    virtual ~Elf();
    
    virtual bool attack(Player *p) override;
    void setGold(std::shared_ptr<Gold> g);
    virtual std::shared_ptr<Gold> onDeath() override;
};

#endif
