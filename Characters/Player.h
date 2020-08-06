#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include "../info.h"

class Tile;
class Enemy;
class Gold;
class Potion;

class Player {
    private:
    char c = '@';
    std::shared_ptr<Tile> location;
    int baseAtk, baseDef;

    protected:
    int hp, atk, def, score, maxHealth;
    
    public:
    Player(int hp, int atk, int def, int maxHealth); //inital constructor
    virtual ~Player();
    
    char getChar() const;
    int getScore() const;
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    int getBaseAtk();
    int getBaseDef();
    std::shared_ptr<Tile> getLocation(); //called by game so the game knows where the player is
    void setLocation( std::shared_ptr<Tile> tile ); //called whenever the player moves to a new tile

    virtual bool attack(Enemy &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Enemy &e)= 0;
    virtual void newPlayer(); //called when there is a new floor
    
    void collectGold(std::shared_ptr<Gold> g);

    friend class Potion;

};

#endif
