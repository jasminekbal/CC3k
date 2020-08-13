#ifndef PLAYER_H
#define PLAYER_H
#include <memory>

class Ground;
class Enemy;
class Gold;
class Potion;
class Dragon;
class Dwarf;
class Elf;
class Halfling;
class Human;
class Merchant;
class Orc;


//Invariant: hp must be between 0 and maxHealth or if maxHealth is -1 then it has no upper bound
// atk and def must be greater than or  equal to 0
class Player {
    private:
    char c = '@';
    char type;
    bool isStair = 0;
    std::shared_ptr<Ground> location;
    int baseAtk, baseDef;
    int checkHp(int hp);
    int checkStat(int val);

    protected:
    int hp, atk, def, score, maxHealth;
    
    void changeAtk(int newA);
    void changeDef(int newD);
    
    public:
    Player(int hp, int atk, int def, int maxHealth, char type); //inital constructor
    virtual ~Player();
    
    void changeHp(int newHp);
    char getChar();
    virtual int getScore() const;
    int getHp();
    int getAtk();
    int getDef();
    int getBaseAtk();
    int getBaseDef();
    // check if player is at stairs and needs new floor
    // MUST change isStair back to 0 using setIsStair() after new floor is created
    bool getIsStair();
    std::shared_ptr<Ground> getLocation(); //called by game so the game knows where the player is
    void setLocation( std::shared_ptr<Ground> g ); //called whenever the player moves to a new tile
    void setIsStair(bool is);

    virtual bool onAttacked(Enemy &e) =0;
    virtual bool attack(Dragon &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Dragon &e)= 0;
    virtual bool attack(Dwarf &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Dwarf &e)= 0;
    virtual bool attack(Elf &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Elf &e)= 0;
    virtual bool attack(Halfling &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Halfling &e)= 0;
    virtual bool attack(Human &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Human &e)= 0;
    virtual bool attack(Merchant &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Merchant &e)= 0;
    virtual bool attack(Orc &e) = 0;  //might return a string if we want to go that route
    virtual bool onAttacked(Orc &e)= 0;
    void newPlayer(); //called when there is a new floor
    char getType();
    
    void collectGold(std::shared_ptr<Gold> g);

    friend class Potion;

};

#endif
