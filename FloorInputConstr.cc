#include "Floor.h"
#include "Tile.h"
#include "Ground.h"
#include "Subject.h"
#include "Observer.h"
#include "TextDisplay.h"
#include "Info.h"
#include "Exceptions.h"
#include "Characters/Drow.h"
#include "Characters/Goblin.h"
#include "Characters/Shade.h"
#include "Characters/Troll.h"
#include "Characters/Vampire.h"
#include "Enemies/Dragon.h"
#include "Enemies/Dwarf.h"
#include "Enemies/Elf.h"
#include "Enemies/Halfling.h"
#include "Enemies/Human.h"
#include "Enemies/Merchant.h"
#include "Enemies/Orc.h"
#include "Items/Gold.h"
#include "Items/DragonGold.h"
#include "Items/BoostAttack.h"
#include "Items/BoostDefence.h"
#include "Items/PoisonHealth.h"
#include "Items/RestoreHealth.h"
#include "Items/WoundAttack.h"
#include "Items/WoundDefence.h"
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>

using namespace std;

/*
implementing 

std::shared_ptr<Enemy> Floor::getEnemy( char c );
std::shared_ptr<Potion> Floor::getPotion( char c );
std::shared_ptr<Gold> Floor::getGold( char c );

std::shared_ptr<Ground> Floor::getGround( int row, int col, char c, State & t );

and 
void Floor::checkDragonGold();
std::shared_ptr<Dragon> Floor::getDragon( int row, int col );
*/
//beginning of code



shared_ptr<Potion> Floor::getPotion( char c ){
    shared_ptr<Potion> potion;
    switch( c ){
        case '0':
            potion = make_shared<RestoreHP>();
            break;
        case '1':
            potion = make_shared<BoostAtk>();
            break;
        case '2':
            potion = make_shared<BoostDef>();
            break;
        case '3':
            potion = make_shared<PoisonHP>();
            break;
        case '4':
            potion = make_shared<WoundAtk>();
            break;
        case '5':
            potion = make_shared<WoundDef>();
            break;
    }
    return potion;
}

std::shared_ptr<Gold> Floor::getGold( char c ){
    std::shared_ptr<Gold> gold;
    int value;
    switch( c ){
        case '6':
            value = 2;
            break;
        case '7':
            value = 1;
            break;
        case '8':
            value = 4;
            break;
    }
    gold = make_shared<Gold>(value);
    return gold;
}

std::shared_ptr<Enemy> Floor::getEnemy( char c ){
    std::shared_ptr<Enemy> enemy;
    switch( c ){
        case 'H':
            enemy = make_shared<Human>();
        case 'W':
            enemy = make_shared<Dwarf>();
        case 'E':
            enemy = make_shared<Elf>();
        case 'O':
            enemy = make_shared<Orc>();
        case 'M':
            enemy = make_shared<Merchant>();
        case 'D':
            enemy = make_shared<Dragon>();
        case 'L':
            enemy = make_shared<Halfling>();
    }
    return enemy;
}

std::shared_ptr<Ground> Floor::getGround(int row, int col, char c, State & t){
    std::shared_ptr<Potion> potion = nullptr;
    std::shared_ptr<Gold> gold = nullptr;
    std::shared_ptr<Enemy> enemy = nullptr;
    int chamber = -1;
    switch( c ){
        case '\\':
            t = State::Stairs;
            break;
        case '.':
            t = State::Ground;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            t = State::Potion;
            potion = getPotion( c );
            break;
        case '6':
        case '7':
        case '8':
            t = State::Gold;
            gold = getGold( c );
            break;
        case '9': {
            t = State::Gold;
            int value = 6;
            gold = make_shared<DragonGold>( value );
            break;
        }
        case 'H':
        case 'W':
        case 'E':
        case 'O':
        case 'M':
        case 'D': 
        case 'L': 
            t = State::Enemy;
            enemy = getEnemy( c );
            break;
        default:
            throw noFile( "not a permitted character");
    }
    return make_shared<Ground>( row, col, t, chamber, enemy, potion, gold );
}

std::shared_ptr<Dragon> Floor::getDragon( int row, int col ){
    int i, j;
    for( i = row - 1; i < row + 2; i ++ ){
        for( j = col -1; j < col + 2; j ++){
            if( i == row && j == col){}
            else
            {
                auto neighbour = tiles[i][j];
                if( neighbour->getChar() == 'D' ){
                    auto ground = static_pointer_cast<Ground>( neighbour );
                    return static_pointer_cast<Dragon>( ground->enemy );
                }
            }
        }
    }
    return nullptr;
}

void Floor::checkDragonGold(){
    for( auto r: tiles ){
        for( auto tile: r ){
            if( tile->type == State::Gold ){ //if it is a gold 
                auto ground = static_pointer_cast< Ground >( tile ); 
                auto dragonGold = dynamic_pointer_cast< DragonGold > ( ground->gold ); //if it is a dragonGold
                if( dragonGold != nullptr ){
                    int row = ground->row;
                    int col = ground->col;
                    auto dragon = getDragon( row, col );
                    if( dragon == nullptr ){
                        throw NoFile( "No dragon with dragonGold" );
                    }
                    dragon->setGold( dragonGold );
                    dragonGold->setDragon( dragon );
                }
            }
        }
    }
}



