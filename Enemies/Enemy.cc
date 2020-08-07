#include "Enemy.h"
using namespace std;

Enemy::Enemy(int hp, int atk, int def, char c){}
bool Enemy::attack(Player &p){ return 0; } 
bool Enemy::onAttacked(Player &p){ return 0; }
std::shared_ptr<Gold> Enemy::onDeath(){ return make_shared<Gold>(1, 1); }

int Enemy::getHp() const{ return hp; }
int Enemy::getAtk() const{ return atk; }
int Enemy::getDef() const{ return def; }
char Enemy::getChar() const{ return c; }