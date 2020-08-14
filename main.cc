#if 1
#include "Items/BoostAttack.h"
#include "Items/BoostDefence.h"
#include "Items/DragonGold.h"
#include "Items/Gold.h"
#include "Items/Item.h"
#include "Items/PoisonHealth.h"
#include "Items/Potion.h"
#include "Items/RestoreHealth.h"
#include "Items/WoundAttack.h"
#include "Items/WoundDefence.h"
#include "Characters/Drow.h"
#include "Characters/Goblin.h"
#include "Characters/Shade.h"
#include "Characters/Troll.h"
#include "Characters/Vampire.h"
#include "Characters/Player.h"
#include "Enemies/Dragon.h"
#include "Enemies/Dwarf.h"
#include "Enemies/Elf.h"
#include "Enemies/Halfling.h"
#include "Enemies/Human.h"
#include "Enemies/Merchant.h"
#include "Enemies/Orc.h"
#include "Enemies/Enemy.h"
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "Tile.h"
#include "Info.h"
#include "Ground.h"
#include "Game.h"
using namespace std;


void getPlayer( shared_ptr<Player> & p ){
    cout << "Please enter a player character. s, d, v, g, t: " << endl;
    char c;
    bool isCharacter = false; 
    while( !isCharacter ){
        if( cin>> c){
            switch( c ){
                case 's':
                    p = make_shared<Shade>();
                    isCharacter = true;
                    break;
                case 'd':
                    p = make_shared<Drow>();
                    isCharacter = true;
                    break;
                case 'v':
                    p = make_shared<Vampire>();
                    isCharacter = true;
                    break;
                case 'g':
                    p = make_shared<Goblin>();
                    isCharacter = true;
                    break;
                case 't':
                    p = make_shared<Troll>();
                    isCharacter = true;
                    break;
                default: 
                    cout << "Sorry not a player character. " << endl;
                    cout << "Please enter a player character. s, d, v, g, t: " << endl;
            }
        } else {
            break;
        }
    }
}

int getDirection( string c ){
    if (c == "nw") return 0;
    else if (c == "no") return 1;
    else if (c == "ne") return 2;
    else if (c == "we") return 3;
    else if (c == "ea") return 4;
    else if (c == "sw") return 5;
    else if (c == "so") return 6;
    else if (c == "se") return 7;
}

void printStats(Player &p, std::string msg){
    /*cout<<message<<endl;
    if (p->getType())
    race = 
    cout<<"Race: "<<""
    */
}

//Notes:
// should game have a print function

int main( int argc, char * argv[] ) 
{   
    std::shared_ptr<Player> p; 
    getPlayer( p );

    if (p->getType()=='S'){

    } else if(p->getType()=='D'){

    }
    std::ifstream infile;
    infile.open("default.txt");
    bool hasFile = false;
    if (argc == 2){
        infile.open(argv[1]);
        hasFile = true;
    }
    
    std::string message = "Player has spawned";
    Game game = Game(p, infile, hasFile );
    game.print();
    printStats( * p, " " );


    return 0;
}



#endif
