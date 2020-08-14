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

void printStats(Player &p, std::string msg, std::string race, Game &g){
    cout<<"Race: "<<race<<" Gold: "<<p.getScore()<<"\t\t\t\t"<<"Floor: "<<g.getLevel()<<endl;
    cout<<"HP: "<<p.getHp()<<endl;
    cout<<"Atk: "<<p.getAtk()<<endl;
    cout<<"Def: "<<p.getDef()<<endl;
    cout<<"Action: "<<msg<<endl;
}


void getName( Player &p, string & name ){
    if (p.getType()=='S'){
        name = "Shade";
    } else if(p.getType()=='D'){
        name = "Drow";
    } else if (p.getType()=='G'){
        name = "Goblin";
    } else if (p.getType()=='T'){
        name = "Troll";
    } else {
        name = "Vampire";
    }
}

Game beginGame( std::shared_ptr<Player> &p, string & name, bool hasFile, string & fileName, ifstream & infile, string & message ){
    getPlayer( p );
    getName( *p, name );
    infile.open(fileName);
    Game game = Game(p, infile, hasFile );
    message = "Player has spawned";
    game.print();
    printStats( * p, message, name, game);
    return game;
}

bool checkCongrats(std::string msg){
    std::string congrats = "CONGRATS";
    for (int i=0; i<=7;i++){
        if (msg[i] != congrats[i]){
            return false;
        }
    }
    return true;
}

bool toMoveEnemies(std::string message){
    if (message == "You have reached Floor 2" || 
    message == "You have reached Floor 3"|| message == "You have reached Floor 4"||
    message == "You have reached Floor 5"){
        return false;
    } else if (message == "You died :("){
        return false;
    } else if (message == "Oh no... GAME OVER!"){
        return false;
    } else  if (checkCongrats(message)){
        return false;
    }
    return true;
}

bool isGameOver(std::string message){
    if(checkCongrats(message)){
        return true;
    } else if (message == "Oh no... GAME OVER!") {
        return true;
    }
    return false;
}


int main( int argc, char * argv[] ) 
{   
    std::shared_ptr<Player> p; 
    std::string name;
    std::ifstream infile;
    
    bool hasFile = false;
    string fileName = "default.txt";
    if (argc == 2){
        hasFile = true;
        fileName = (argv[1]);
    }
    std::string message;
    
    bool playAgain = true;

    while(playAgain){
    
        Game game = beginGame( p, name, hasFile, fileName, infile, message );
        
        while (true){
            cout<<"Enter your move: "<<endl;
            std::string cmd;

            cin>>cmd;
            int dir;
            //get cmd
            if (cmd =="no" || cmd =="so"|| cmd =="ea"||cmd=="we"|| cmd=="ne"||cmd=="nw"||cmd=="se"||cmd=="sw"){
                dir = getDirection(cmd);
                message = game.moveCharacter(dir);
                if (message == ""){
                    message = "Player moved " + cmd;
                }
                game.print();
                printStats( * p, message, name, game);
                if (toMoveEnemies(message)){
                    message = game.tick();
                    if (message == "" && game.getMoveEnemies()){
                        message = "Enemies moved";
                    } else if (message == "" && !game.getMoveEnemies()) {
                        message = "Enemies did not move";
                    }
                    game.print();
                    printStats( * p, message, name, game);
                }
                if (isGameOver(message)){
                    break;
                }
            } else if (cmd[0] =='u' ||cmd[0]=='a' ){
                cin>>cmd;
                dir = getDirection(cmd);
                message = game.moveCharacter(dir);
                game.print();
                printStats( * p, message, name, game);
                if (toMoveEnemies(message)){
                    message = game.tick();
                    if (message == "" && game.getMoveEnemies()){
                        message = "Enemies moved";
                    } else if (message == "" && !game.getMoveEnemies()) {
                        message = "Enemies did not move";
                    }
                }
                game.print();
                printStats( * p, message, name, game);
                if (isGameOver(message)){
                    break;
                }
            } else if (cmd == "f"){
                game.setMoveEnemies();
                if (game.getMoveEnemies()) {
                    message="Enemies will move and attack you!";
                } else {
                    message="Enemies are sleeping and will not move/harm you!";
                }
                game.print();
                printStats( * p, message, name, game);
            } else if (cmd == "r"){
                infile.close();
                message = "The game has restarted";
                break;
            } else if (cmd == "q"){
                message = "You Have Admitted defeat!";
                game.print();
                printStats( * p, message, name, game);
                break;
            }
        }
        cout<<"Would You Like To Play Again?(enter 'y' or 'n')"<<endl;
        char play;
        cin>>play;
        if (play=='y'){
            playAgain = true;
        } else {
            playAgain = false;
        }
        
    }

    return 0;
}

#endif
