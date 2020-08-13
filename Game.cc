#include "Game.h"
#include "Floor.h"
#include "TextDisplay.h"
#include "./Characters/Player.h"
#include <string>
#include <memory>
#include <fstream>
#include "Ground.h"
using namespace std;

Game::Game(shared_ptr<Player> py){
    p=py;
    td = make_shared<TextDisplay> ();
    newFloor();
}

Game::Game(shared_ptr<Player> py, std::istream &input){
    p=py;
    td = make_shared<TextDisplay> ();
    newFloor(input);
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
    if (checkPlayerState()==1){
        newFloor();
    }
}

void Game::newFloor(){
    std::ifstream infile{ "default.txt" };
    f = make_unique<Floor>(td, infile, p); 
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

std::string Game::moveCharacter( int dir ){
    return (p->getLocation())->movePlayer(dir);
}
 
