#include "Player.h"

#include "../Ground.h"
#include "../Enemies/Enemy.h"
#include "../Items/Gold.h"
#include "../Items/Potion.h"
#include "../Exceptions.h"
#include <iostream>

using namespace std;

int Player::checkHp(int h) {
    if (maxHealth == -1){
        return h;
    } else if( h <= maxHealth && h >=0 ) {
        return h;
    } else if (h> maxHealth) {
        return maxHealth;
    } else {
        return 0;
    }
}

char Player::getType(){
    return type;
}

int Player::checkStat(int val) {
    if (val >= 0) {
        return val;
    } else {
        return 0;
    }
}

void Player::changeHp(int newHp){
    hp = checkHp(newHp);
}

void Player::changeAtk(int newA){
    atk = checkStat(newA);
}

void Player::changeDef(int newD){
    def = checkStat(newD);
}

Player::Player(int hp, int atk, int def, int maxHealth, char type)
: hp(hp), atk(atk), baseAtk(atk), baseDef(def), def(def), maxHealth(maxHealth), score(0), type(type) {}

Player::~Player(){

}
    
char Player::getChar() {
    return c;
}

int Player::getScore() const{
    return score;
}

int Player::getHp(){
    return hp;
}

int Player::getAtk() {
    return atk;
}   

int Player::getDef(){
    return def;
}

int Player::getBaseAtk(){
    return baseAtk;
}

int Player::getBaseDef(){
    return baseDef;
}

Ground * Player::getLocation(){
    return location;
}

void Player::setLocation( Ground *tile ){
    location = tile;
}

bool Player::getIsStair(){
    return isStair;
}

void Player::setIsStair(bool is){
    isStair = is;
}

void Player::newPlayer(){
    atk = baseAtk;
    def = baseDef;
}
    
void Player::collectGold(shared_ptr<Gold> g){
    if (g->getCanCollect()){
        //cout << "Hello" << endl;
        //score ++;
        //cout << "score: " << score << endl;
        //cout << "getting change: " << g->getChange() << endl;
        score += g->getChange();
    }else {
        throw CantCollect("Can't collect gold");
    }
}


