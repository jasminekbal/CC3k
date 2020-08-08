#include "Player.h"

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

void Player::changeHp(int newHp){
    hp = checkHp(newHp);
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

}
