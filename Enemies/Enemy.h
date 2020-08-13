#ifndef ENEMY_H
#define ENEMY_H
#include <memory>

class Gold;
class Player;
class Vampire;
class Troll;
class Shade;
class Goblin;
class Drow;

class Enemy{
    private:
        char c; // to be set during construction
        int hp, atk, def;
        int checkHp(int hp);
        int checkStat(int val);

    protected:

        //might not need this depending on implementaion 
        void setHP(int hp);
        void setAtk(int atk);
        void setDef(int def);
        bool randAtk( );
        bool defaultAtk(Player &p);
        bool defaultOnAtk(Player &p);

    public:
        Enemy(int hp, int atk, int def, char c);
        virtual ~Enemy();
        
        virtual bool onAttacked( Player & p ) = 0;

        virtual bool attack(Drow &d) = 0;  // this returns if the attack was succesful
        virtual bool onAttacked(Drow &d)= 0;
        virtual bool attack(Goblin &g) = 0;  // this returns if the attack was succesful
        virtual bool onAttacked(Goblin &g)= 0;
        virtual bool attack(Shade &s) = 0;  // this returns if the attack was succesful
        virtual bool onAttacked(Shade &s)= 0;
        virtual bool attack(Troll &t) = 0;  // this returns if the attack was succesful
        virtual bool onAttacked(Troll &t)= 0;
        virtual bool attack(Vampire &v) = 0;  // this returns if the attack was succesful
        virtual bool onAttacked(Vampire &v)= 0;
        virtual std::shared_ptr<Gold> onDeath() = 0;

        int getHp() const; // we need to know if dead
        int getAtk() const; //needed when enemy attacks a player
        int getDef() const;
        char getChar() const; //to see how to display
        virtual bool isHostile();
};

#endif
