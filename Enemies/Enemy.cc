#include "Enemy.h"
#include "../Items/Gold.h"

//will do later
void Enemy::setGold( std::shared_ptr<Gold> gP ){

}

void Enemy::setHP(int hp){
    hp = hp;
}
void Enemy::setAtk(int atk){
    atk = atk;
}
void Enemy::setDef(int def){
    def = def;
}

Enemy::Enemy(int hp, int atk, int def, char c): hp(hp), atk(atk), def(def), c(c){}

Enemy::~Enemy(){

}
       

std::shared_ptr<Gold> Enemy::onDeath(){
    return make_shared<Gold>(1, 1);
}

//will do later
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

