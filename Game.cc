#include "Game.h"
#include "Floor.h"
#include "TextDisplay.h"
#include "./Characters/Player.h"
#include <string>
#include "Ground.h"


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
}

void Game::newFloor(){
    std::ifstream infile{ "default.txt" };
    
}

void Game::newFloor( std::istream & input ){
    f = std::make_unique<Floor>(td, input, p);
}


std::string Game::endGame( bool showScore ){
    if (showScore){
        return "CONGRATS! Your Score is "+ std::to_string(p->getScore())+"!";
    } else {
        return "Oh no... GAME OVER!";
    }
}

void Game::moveCharacter( int dir ){
    (p->getLocation())->movePlayer(dir);
}
    
std::string Game::interact( int dir ){

    return "interact ";
}
