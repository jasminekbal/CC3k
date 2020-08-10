#ifndef ENEMY_H
#define ENEMY_H
#include <memory>

class Gold;
class Player;

class Enemy{
    private:
        char c; // to be set during construction
        int hp, atk, def;

    protected:
        std::shared_ptr<Gold> goldPile;
        void setGold( std::shared_ptr<Gold> gP );

        //might not need this depending on implementaion 
        void setHP(int hp);
        void setAtk(int atk);
        void setDef(int def);

    public:
        Enemy(int hp, int atk, int def, char c);
        virtual ~Enemy();
        virtual bool attack(Player &p) = 0;  // 0 is did not die, 1 is died // might return a string if we want to go that route
        virtual bool onAttacked(Player &p)= 0;
        virtual std::shared_ptr<Gold> onDeath();

        int getHp() const; // we need to know if dead
        int getAtk() const; //needed when enemy attacks a player
        int getDef() const;
        char getChar() const; //to see how to display
};

#endif
