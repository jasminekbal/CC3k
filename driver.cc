#if 0
#include "Items/BoostAttack.h"
#include "Items/BoostDefence.h"
#include "Items/DragonGold.h"
#include "Items/Gold.h"
#include "Items/Item.h"
#include "Items/PoisonHealth.h"
#include "Items/Potion.h"
#include "Items/RestoreHealth.h"
#include "Items/WoundAttack.h"
#include "Items/WoundDefence.h"
#include "Characters/Drow.h"
#include "Characters/Goblin.h"
#include "Characters/Shade.h"
#include "Characters/Troll.h"
#include "Characters/Vampire.h"
#include "Characters/Player.h"
#include "Enemies/Dragon.h"
#include "Enemies/Dwarf.h"
#include "Enemies/Elf.h"
#include "Enemies/Halfling.h"
#include "Enemies/Human.h"
#include "Enemies/Merchant.h"
#include "Enemies/Orc.h"
#include "Enemies/Enemy.h"
#include <iostream>
#include <string>
#include <memory>
#include "Tile.h"
#include "Info.h"
#include "Ground.h"


using namespace std;

void print(shared_ptr<Player> p, shared_ptr<Enemy> e, vector<shared_ptr<Tile > > & floor ){
    for( auto tile : floor ){
        cout << tile->getChar();
    }
    cout <<endl;
    if( p != nullptr ){
        cout<<"Player:" << endl;
        cout << "attack : " << p->getAtk() << endl;
        cout << "defence : " << p->getDef() << endl;
        cout << "health : " << p->getHp() << endl;
        cout << "gold: " << p->getScore() << endl;
        cout << endl;
    }
    if( e != nullptr ){
        cout<<"Enemy:" << endl;
        cout << "attack : " << e->getAtk() << endl;
        cout << "defence : " << e->getDef() << endl;
        cout << "health : " << e->getHp() << endl;
    }
}



void movement( shared_ptr<Player> & p, vector<shared_ptr<Tile> > & floor ){
    shared_ptr<Ground> ground;
    char c;
    int i;
    while( cin >> c ){
        switch( c ){
            case 'A': 
                if( cin >> i ){
                    ground =  static_pointer_cast<Ground>( floor[i] );
                    ground->setPlayer( p );
                    p->setLocation( ground );
                }
                break;
            case 'l':
                
            case 'r':
            
            case 'p':
                print( p, nullptr, floor );
        }
    }
}


int main(){
    shared_ptr<Player> p;
    char c = ' ';
    shared_ptr<Potion> potion;
    shared_ptr<Gold> gold;
    shared_ptr<Enemy> enemy;
    shared_ptr<Tile> tile;
    shared_ptr<Ground> ground;
    vector<shared_ptr<Tile> > floor;
    int row, col = 0;
    int value = 2;
    bool canCollect = true;
    while( cin >> c ){
        switch( c ){
            case 's':
                p = make_shared<Shade>();
                break;
            case 'd':
                p = make_shared<Drow>();
                break;
            case 'v':
                p = make_shared<Vampire>();
                break;
            case 'g':
                p = make_shared<Goblin>();
                break;
            case 't':
                p = make_shared<Troll>();
                break;
            case '0':
                potion = make_shared<RestoreHP>();
                cout << "RH" << endl;
            case '1':
                potion = make_shared<BoostAtk>();
                cout << "BA" << endl;
                break;
            case '2':
                potion = make_shared<BoostDef>();
                cout << "BD" << endl;
                break;
            case '3':
                potion = make_shared<PoisonHP>();
                cout << "PH" << endl;
                break;
            case '4':
                potion = make_shared<WoundAtk>();
                cout << "WA" << endl;
                break;
            case '5':
                potion = make_shared<WoundDef>();
                cout << "WD" << endl;
                break;
            case '6':
                gold = make_shared<Gold>(value, canCollect);
                p->collectGold( gold );
                break;
            case 'H':
                enemy = make_shared<Human>();
                break;
            case 'W':
                enemy = make_shared<Dwarf>();
                break;
            case 'E':
                enemy = make_shared<Elf>();
                break;
            case 'O':
                enemy = make_shared<Orc>(); 
                break;
            case 'M':
                enemy = make_shared<Merchant>();
                break;
            case 'D':
                enemy = make_shared<Dragon>();
                break;
            case 'L':
                enemy = make_shared<Halfling>();
                break;
            case 'p':
                print(p, enemy, floor );
                break;
            case 'a':
                if( enemy->onAttacked( * p ) ){
                    if( enemy->getHp() <= 0 ){
                        gold = enemy->onDeath();
                        p->collectGold( gold );
                    }
                }
                break;
            case 'o':
                p->onAttacked( *enemy );
                break;
            case 'u':
                potion->usePotion( p );
                break;
            case 'q':
                break;
            case 'r':
                cout << rand() << endl;
            case '7':
                tile = make_shared<Tile>(row, col, State::HorizontalWall);
                floor.push_back( tile );
                cout << "Tile " << tile->getChar() << endl; 
                break;
            case '8':
                ground = make_shared<Ground>(row, col, State::Ground);
                floor.push_back( ground );
                cout << "Ground " << ground->getChar() << endl; 
                break;
            case     
        }
  }

#endif
