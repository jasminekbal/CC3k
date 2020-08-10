#include "Player.h"
class Ground;
class Enemy;
class Gold;
class Potion;
#include "../Ground.h"
#include "../Enemies/Enemy.h"
#include "../Items/Gold.h"
#include "../Items/Potion.h"

int Player::checkHp(int hp) const {
    if (maxHealth == -1){
        return hp;
    } else if( hp <= maxHealth && hp >=0 ) {
        return hp;
    } else if (hp> maxHealth) {
        return maxHealth;
    } else {
        return 0;
    }
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

Player::Player(int hp, int atk, int def, int maxHealth)
: hp(hp), atk(atk), baseAtk(atk), baseDef(def), def(def), maxHealth(maxHealth), score(0) {}

Player::~Player(){

}
    
char Player::getChar() const {
    return c;
}

int Player::getScore() const{
    return score;
}

int Player::getHp() const{
    return hp;
}

int Player::getAtk() const {
    return atk;
}   

int Player::getDef() const{
    return def;
}

int Player::getBaseAtk(){
    return baseAtk;
}

int Player::getBaseDef(){
    return baseDef;
}

std::shared_ptr<Ground> Player::getLocation(){
    return location;
}

void Player::setLocation( std::shared_ptr<Ground> tile ){
    location = tile;
}

void Player::newPlayer(){
    atk = baseAtk;
    def = baseDef;
}
    
//will do later
void Player::collectGold(std::shared_ptr<Gold> g){
    if (g->getCanCollect()){
        score += g->getChange();
    }
}


