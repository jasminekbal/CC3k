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
                break;
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
        }
        potion->usePotion( p );

        cout << "attack : " << p->getAtk() << endl;
        cout << "defence : " << p->getDef() << endl;
        cout << "health : " << p->getHp() << endl;
    }
}

#endif


