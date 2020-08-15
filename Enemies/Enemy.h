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
        virtual ~Enemy() =0;
        
        bool baseOnAtk(Player & p);

        virtual bool attack(Player * p);
        virtual bool onAttacked(Player & p);

        virtual std::shared_ptr<Gold> onDeath() = 0;

        int getHp() const; // we need to know if dead
        int getAtk() const; //needed when enemy attacks a player
        int getDef() const;
        char getChar() const; //to see how to display
        virtual bool isHostile();
        virtual void makeHostile();

        virtual void setHasAttacked( bool b ){}
        virtual bool getHasAttacked() {return false;}
};

#endif
