#include "Enemy.h"
#include "../Items/Gold.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include "../Characters/Player.h"

using namespace std;

int Enemy::checkHp(int h) {
    if (h >= 0){
        return h;
    } else {
        return 0;
    }
}

int Enemy::checkStat(int val) {
    if (val >= 0) {
        return val;
    } else {
        return 0;
    }
}

void Enemy::setHP(int hp){
    this->hp = checkHp(hp);
}

void Enemy::setAtk(int atk){
    atk = checkStat(atk);
}
void Enemy::setDef(int def){
    def = checkStat(def);
}

Enemy::Enemy(int hp, int atk, int def, char c): c(c), hp(hp), atk(atk), def(def){
}

Enemy::~Enemy(){

}

int Enemy::getHp() const{
    return hp;
}

int Enemy::getAtk() const{
    return atk;
}

int Enemy::getDef() const{
    return def;
}

char Enemy::getChar() const{
    return c;
}

bool Enemy::randAtk( ){
    int randNum = ( rand() % 2);
    if (randNum == 1){
        return true;
    } else {
        return false;
    }
}

bool Enemy::isHostile(){
    return true;
}

bool Enemy::attack(Player * p){
    bool toAtk = this->randAtk();
    if (toAtk){
        p->onAttacked(* this);
        return true;
    } else {
        return false;
    }
}

bool Enemy::onAttacked(Player & p){
    double tempDamage = ceil( (100.0/(100.0+(double) getDef()))* (double) p.getAtk());
    int damage = (int) floor( tempDamage );
    hp = checkHp(hp - damage);
    return true;
}

void Enemy::makeHostile(){
    
}

