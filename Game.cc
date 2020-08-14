#include "Game.h"
#include "Floor.h"
#include "TextDisplay.h"
#include "./Characters/Player.h"
#include <string>
#include <memory>
#include <fstream>
#include "Ground.h"
using namespace std;


Game::Game(shared_ptr<Player> py, std::istream &input){
    p=py;
    td = make_shared<TextDisplay> ();
    infile = input;
    level = 1;
    newFloor();
}

int Game::checkPlayerState(){
    if (p->getIsStair()){
        return 1;
    } else if(p->getHp()==0) {
        return 2;
    } else {
        return 0;
    }
}

void Game::tick(){
    f->moveEnemies();
    if (p->getType()== 'T'){
        p->changeHp(p->getHp()+5);
    }
    if( checkPlayerState() == 2){
        endGame( false );
    }
}

void Game::newFloor(){
    f = std::make_unique<Floor>(td, infile, p);
}


std::string Game::endGame( bool showScore ){
    if (showScore){
        return "CONGRATS! Your Score is "+ std::to_string(p->getScore())+"!";
    } else {
        return "Oh no... GAME OVER!";
    }
}

std::string Game::moveCharacter( int dir ){
    string message = (p->getLocation())->movePlayer(dir);
    if (checkPlayerState() == 2){
        message = "You died :(";
    }else if (checkPlayerState()==1){
        if (level < 5){
            level ++ ;
            f = newFloor(infile);
            message = "You have reached Floor " + std::to_string(level);
        } else {
            return endGame(true);
        }
    }
    return message;
}
 
