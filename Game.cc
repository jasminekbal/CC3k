#include "Game.h"
#include "Floor.h"
#include "Exceptions.h"
#include "TextDisplay.h"
#include "./Characters/Player.h"
#include <string>
#include <memory>
#include <fstream>
#include <iostream> 
#include "Ground.h"

using namespace std;

Game::Game(shared_ptr<Player> py, std::istream &input, bool hasFile ): p{py}, infile{input}, hasFile{hasFile} {
    //cout << "@ Game constructor" << endl;
    td = make_shared<TextDisplay> ();
    moveEnemies = true;
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

Game::~Game(){

}

int Game::getLevel(){
    return level;
}

std::string Game::tick(){
    std::string msg;
    if( moveEnemies ){
       msg = f->moveEnemies();
    }
    if (p->getType()== 'T'){
        p->changeHp(p->getHp()+5);
    }
    if( checkPlayerState() == 2){
        msg = endGame( false );
    }
    return msg;
}

void Game::newFloor(){
    delete f;
    cout << "1. In new floor, Location is null: " << (p->getLocation() ==nullptr) <<endl;
    f = new Floor(td, infile, p);
    cout << "2. In new floor, Location is null: " << (p->getLocation() ==nullptr) <<endl;
    if( !hasFile ){
        f->generate(p);
    }
    cout << "3. In new floor, Location is null: " << (p->getLocation() ==nullptr) <<endl;
}

void Game::setMoveEnemies(){
    moveEnemies = !moveEnemies;
}

bool Game::getMoveEnemies(){
    return moveEnemies;
}

std::string Game::endGame( bool showScore ){
    if (showScore){
        return "CONGRATS! Your Score is "+ std::to_string(p->getScore())+"!";
    } else {
        return "Oh no... GAME OVER!";
    }
}

void Game::print(){
    cout<< * td << endl;
}

std::string Game::moveCharacter( int dir ){
    string message = "";
    try{
        cout << "getting location" << endl;
        p->getLocation();
        cout << "got location " << (p->getLocation() == nullptr) << endl;
        message = (p->getLocation())->movePlayer(dir) + "\n";
    }
    catch (WallMove e){
        message = "You tried to move to a wall, now your face hurts\n";
        return message;
    }
    
    if (checkPlayerState() == 2){
        message = message + "You died :(" + "\n";
    }else if (checkPlayerState()==1){
        if (level < 5){
            level ++ ;
            newFloor();
            message = message + "You have reached Floor " + std::to_string(level) + "\n";
        } else {
            return endGame(true);
        }
    }
    return message;
}
 
