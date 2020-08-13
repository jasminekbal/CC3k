#if 1
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
#include "Enemies/Enemy.h"
#include "Enemies/Dragon.h"
#include "Enemies/Dwarf.h"
#include "Enemies/Elf.h"
#include "Enemies/Halfling.h"
#include "Enemies/Human.h"
#include "Enemies/Merchant.h"
#include "Enemies/Orc.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(){
    shared_ptr<Player> p;
    char c = ' ';
    bool madeCharacter = false;
    while( !madeCharacter ){
        if( cin>> c){
            switch(c){
                case 's':
                    p = make_shared<Shade>();
                    madeCharacter = true;
                    break;
                case 'd':
                    p = make_shared<Drow>();
                    madeCharacter = true;
                    break;
                case 'v':
                    p = make_shared<Vampire>();
                    madeCharacter = true;
                    break;
                case 'g':
                    p = make_shared<Goblin>();
                    madeCharacter = true;
                    break;
                case 't':
                    p = make_shared<Troll>();
                    madeCharacter = true;
                    break;
            }
        }
        break;
    }
    cout << "created: " << c << endl;
    shared_ptr<Potion> potion;
    shared_ptr<Enemy> enemy;
    while( cin >> c ){
        switch( c ){
            case '0':
                potion = make_shared<RestoreHP>();
                cout << "RH" << endl;
                potion->usePotion( p );
                break;
            case '1':
                potion = make_shared<BoostAtk>();
                cout << "BA" << endl;
                potion->usePotion( p );
                break;
            case '2':
                potion = make_shared<BoostDef>();
                cout << "BD" << endl;
                potion->usePotion( p );
                break;
            case '3':
                potion = make_shared<PoisonHP>();
                cout << "PH" << endl;
                potion->usePotion( p );
                break;
            case '4':
                potion = make_shared<WoundAtk>();
                cout << "WA" << endl;
                potion->usePotion( p );
                break;
            case '5':
                potion = make_shared<WoundDef>();
                cout << "WD" << endl;
                potion->usePotion( p );
                break;
            case 'H':
                enemy = make_shared<Human>();
                p->onAttacked( *enemy );
                break;
            case 'W':
                enemy = make_shared<Dwarf>();
                p->onAttacked( *enemy );
                break;
            case 'E':
                enemy = make_shared<Elf>();
                p->onAttacked( *enemy );
                break;
            case 'O':
                enemy = make_shared<Orc>();
                p->onAttacked( *enemy );
                break;
            case 'M':
                enemy = make_shared<Merchant>();
                p->onAttacked( *enemy );
                break;
            case 'D':
                enemy = make_shared<Dragon>();
                p->onAttacked( *enemy );
                break;
            case 'L':
                enemy = make_shared<Halfling>();
                p->onAttacked( *enemy );
                break;
        }
        cout << "attack : " << p->getAtk() << endl;
        cout << "defence : " << p->getDef() << endl;
        cout << "health : " << p->getHp() << endl;
    }
}

#endif


