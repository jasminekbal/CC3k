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
#include "Exceptions.h"
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
    while( !isCharacter && cin>> c && !( cin.fail() ) && ! (cin.eof() ) ){
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
    }
}

void pressAnyKey(){
    cout << endl << "Press any key to continue" << endl;
    getchar(); // waits for key press
}

void checkCorrectInp(std::string check){
    std::string cmd = "";
    while (cin>>cmd){
        if (cmd==check){
            return;
        }
        else{
            cout << "You have to type " << check << "." <<endl;
            cout << "What? did you think you had free will?" << endl;
        }
    }
}

void printStats(Player &p, std::string msg, std::string race, Game &g){
    cout<<"Race: "<<race<< "\t\t\t"<<" Gold: "<<p.getScore()<<"\t\t\t"<<"Floor: "<<g.getLevel()<<endl;
    cout<<"HP: "<<p.getHp()<<endl;
    cout<<"Atk: "<<p.getAtk()<<endl;
    cout<<"Def: "<<p.getDef()<<endl;
    cout<<"Action: "<<msg<<endl;
}

void demo(){
    getchar();
    std::ifstream infile;
    std::string message = "";

    cout << endl << "Welcome to cc3k-villain!" << endl << endl;
    cout << "Unfortunately, you have gotten yourself trapped in a dungeon :(" << endl;
    cout << "The only way to escape this dungeon is to climb your way to the top using the stairs on each floor." << endl;
    cout << "But, while you're here, you might as well collect gold by picking it up or killing monsters." << endl;

    pressAnyKey();

    cout << "Right, monsters. Did I forget to mention that?" << endl;
    cout << "This dungeon is filled with all sorts of enemies including orcs, dragons, elves, and worst of all, humans. *shudder*" << endl;

    pressAnyKey();

    cout << "You can also choose what type of player you will be. Each player and enemy has unique abilities." << endl;
    cout << "For this tutorial, you'll be a shade." << endl;
    cout << "Let's get into the tutorial. Don't forget to have fun and kick monster butt!" << endl;

    pressAnyKey();

    infile.open("demo1.txt");
    std::shared_ptr<Player> p = make_shared<Shade>();
    Game game = Game(p, infile, 1);
    game.print();

    cout << endl<<"This is the first floor. Potions are shown as the character 'P'. Gold is shown as 'G'. "
    << "Each type of enemy is shown as a different character" << endl;
    cout << "A floor's contents are randomly generated unless you enter a file name as a command line argument." << endl;
    cout << "You can type the direction you want to move to as 'no', 'ne', 'ea', 'se', etc." << endl;
    cout << "Let's see what happens when you move North East (ne):" << endl << endl;

    checkCorrectInp("ne");
    message = game.moveCharacter(2);
    game.print();
    printStats(*p, message, "shade", game);
    cout << message << endl;
    game.tick();
    game.print();
    printStats(*p, message, "shade", game);

    cout << endl <<"So you stepped on a potion. You can't know what a potion does until you step on it. "
    << "This particular potion boosts your attack level!" << endl;
    cout << "You may have noticed that after you move, most of your enemies will move a tile too." << endl;
    cout << "Be careful not to get too close to them unless you want to fight." << endl << endl;

    cout << endl << "Next, let's try to collect a gold. Move east." << endl << endl;
    checkCorrectInp("ea");
    message = game.moveCharacter(4);
    game.print();
    printStats(*p, message, "shade", game);
    cout << message << endl;
    game.tick();
    game.print();
    printStats(*p, message, "shade", game);

    cout << endl << "And east one more time." << endl << endl;
    checkCorrectInp("ea");
    message = game.moveCharacter(4);
    game.print();
    printStats(*p, message, "shade", game);
    cout << message << endl;
    game.tick();
    game.print();
    printStats(*p, message, "shade", game);

    cout << "Nice! Your score increased!" << endl;
    cout << "You can walk between rooms through passageways. Try moving east to the stairs." << endl << endl;
    for (int x=0;x<15;x+=1){
        checkCorrectInp("ea");
        message = game.moveCharacter(4);
        game.print();
        printStats(*p, message, "shade", game);
        cout << message << endl << endl;
        game.tick();
        game.print();
        printStats(*p, message, "shade", game);
    }

    cout << endl << "You got to the next floor. Now let's try attacking an enemy." << endl << endl;
    cout << "Try moving west to the orc." << endl << endl;
    checkCorrectInp("we");
    message = game.moveCharacter(3);
    game.print();
    printStats(*p, message, "shade", game);
    cout << message << endl << endl;
    game.tick();
    game.print();
    printStats(*p, message, "shade", game);

    cout << "Ouch. The orc tried to attack you because you came close to it." << endl;
    cout << "You can attack back by typing 'a' and a direction." << endl;
    cout << "We thought it would be more intuitive to attack by simply typing in the direction you want to attack." << endl;
    cout << "Try typing 'we' again to attack." << endl << endl;
    checkCorrectInp("we");
    message = game.moveCharacter(3);
    game.print();
    printStats(*p, message, "shade", game);
    cout << message << endl << endl;
    game.tick();
    game.print();
    printStats(*p, message, "shade", game);

    getchar();
    cout << "Fantastic! You really showed him/ her!" << endl;
    cout << "Now you're ready. Go on and explore the dungeon yourself." << endl << endl;

    pressAnyKey();

    cout << endl << endl << endl;
}

void getDemo(){
    cout << "Would you like to go through a short tutorial? (y/n) " << endl;
    char c;
    while( true ){
        if( cin>> c){
            switch( c ){
                case 'y':
                    demo();
                    return;
                case 'n':
                    return;
                default: 
                    cout << "Sorry I didn't catch that. " << endl;
                    cout << "Please enter either the character 'y' or 'n': " << endl;
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

Game beginGame( std::shared_ptr<Player> &p, string & name, bool hasFile, string & fileName, ifstream & infile, string & message, int difficulty ){
    getPlayer( p );
    if( p == nullptr ) throw NoFile( "No input player ");
    getName( *p, name );
    infile.open(fileName);
    try{
        Game game = Game( p, infile, hasFile, difficulty );
        message = "Player has spawned";
        game.print();
        printStats( * p, message, name, game);
        return game;
    }
    catch( NoFile & e ){
        cout << e.getMessage() << endl;
    }
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

bool isGameOver(std::string message){
    if( checkCongrats(message) ){
        return true;
    } else if (message == "Oh no... GAME OVER!") {
        return true;
    }
    return false;
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
    } else  if (isGameOver(message)){
        return false;
    }
    return true;
}

int getDifficulty(){
    std::string inp;
    cout << "What difficulty would you like to play at? Enter a number between 0 and 3 where 0 is the default (and also the easiest):" << endl;
    while (cin >> inp){
        try{
            int dif = stoi(inp);
            if (0 <= dif && dif <= 3) return dif;
            else cout << endl << "Please enter an integer between 0 and 3 inclusive:" << endl << endl;
        }
        catch(std::invalid_argument const &e){
            cout << endl << "Please enter an integer between 0 and 3 inclusive:" << endl << endl;
        }
    }
    cout << endl << endl;
}

bool nextFloor(std::string message){
     if (message == "You have reached Floor 2" || 
    message == "You have reached Floor 3"|| message == "You have reached Floor 4"||
    message == "You have reached Floor 5"){
        return true;
    }
    return false;
}

int main( int argc, char * argv[] ) 
{   
    bool playAgain = true;
    getDemo();
    while(playAgain){
        std::shared_ptr<Player> p = nullptr; 
        std::string name;
        std::ifstream infile;
    
        bool hasFile = false;
        string fileName = "default.txt";
        int difficulty = 0;
        if (argc == 2){
            hasFile = true;
            fileName = (argv[1]);
        }
        else{
            difficulty = getDifficulty();
        }
        std::string message;
        try{
            Game game = beginGame( p, name, hasFile, fileName, infile, message, difficulty );
            std::string cmd;
            cout<<"Enter your move: "<<endl;
            while (cin >> cmd ){
                
                int dir;
                //get cmd
                if (cmd =="no" || cmd =="so"|| cmd =="ea"||cmd=="we"|| cmd=="ne"||cmd=="nw"||cmd=="se"||cmd=="sw"){
                    dir = getDirection(cmd);
                    message = game.moveCharacter(dir);
                    if (message == ""){
                        message = "Player moved " + cmd;
                    }
                    
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
                    if (nextFloor(message)){
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
                    if (nextFloor(message) || isGameOver(message)){
                        break;
                    }
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
                    cout<< "The game has restarted"<<endl;
                    break;
                } else if (cmd == "q"){
                    message = "You Have Admitted defeat!";
                    game.print();
                    printStats( * p, message, name, game);
                    break;
                }
                cout<<"Enter your move: "<<endl;
            } 
            if( cin.fail() || cin.eof() ){
                break;
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
        catch(Exceptions e){
            cout << e.getMessage() << endl;
            break;
        }
        
    }

    return 0;
}

#endif
