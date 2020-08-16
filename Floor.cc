#include "Floor.h"
#include "Tile.h"
#include "RandomGen/RandomGeneration.h"
#include "RandomGen/RandomEnemy.h"
#include "RandomGen/RandomPotion.h"
#include "RandomGen/RandomGold.h"
#include "Ground.h"
#include "Characters/Player.h"
#include "Enemies/Enemy.h"
#include "Items/Gold.h"
#include "Items/Potion.h"
#include "Items/DragonGold.h"
#include "Exceptions.h"
#include "Floor.h"
#include "Tile.h"
#include "Ground.h"
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
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

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
    gold = make_shared<Gold>(value, true);
    return gold;
}

std::shared_ptr<Enemy> Floor::getEnemy( char c ){
    std::shared_ptr<Enemy> enemy;
    switch( c ){
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
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
            t = State::Ground;
            chamber = c - 'a';
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
        case '9':
            t = State::DragonGold;
            gold = make_shared<DragonGold>();
            break;
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
        {
            cout << c << endl;
            string message = "not a permitted character" ;
            throw NoFile( message );
        }
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
                //cout << "row " << i << " col " << j << neighbour->c << endl;
                if( neighbour->getChar() == 'D' ){
                    auto ground = static_pointer_cast<Ground>( neighbour );
                    auto dragon  = static_pointer_cast<Dragon>( ground->getEnemy() );
                    auto gold = dragon->getGold();
                    if( gold == nullptr ){
                        return dragon;
                    } 
                }
            }
        }
    }
    return nullptr;
}

void Floor::checkDragonGold(){
    for( auto r: tiles ){
        for( auto tile: r ){
            if( tile->type == State::DragonGold ){ //if it is a gold 
                auto ground = dynamic_pointer_cast< Ground >( tile ); 
                auto dragonGold = dynamic_pointer_cast< DragonGold > ( ground->getGold() ); //if it is a dragonGold
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

void Floor::addTile( int row, int col, char c, std::shared_ptr<Player> p ){
    std::shared_ptr<Tile> tile = nullptr;
    std::shared_ptr<Ground> ground = nullptr;
    State t;
    int chamber = -1;
    switch( c ){
        case '|':
            t = State::VerticalWall;
            tile = make_shared<Tile>(row, col, t);
            break;
        case '-':
            t = State::HorizontalWall;
            tile = make_shared<Tile>(row, col, t);
            break;
        case ' ':
            t = State::Whitespace;
            tile = make_shared<Tile>(row, col, t);
            break;
        case '@':
            t = State::Player;
            ground = make_shared<Ground>(row, col, t, -1, nullptr, nullptr, nullptr, p);
            player = ground;
            p->setLocation( ground.get() ); //players need a way to set location
            break;
        case '+':
            t = State::Door;
            ground = make_shared<Ground>( row, col, t, chamber );
            break;
        case '#':
            t = State::Passageway;
            ground = make_shared<Ground>( row, col, t, chamber );
            break;
        default:
            ground = getGround( row, col, c, t );
            break;
    }
    //cout << "@ Floor input stream, addTile " << c << endl;
    if( tile != nullptr ){
        tiles[row].push_back( tile );
    }
    else{
        tiles[row].push_back( ground );
    }
}

//we can change this implementation if it doesn't work out 
void Floor::addNeighbours( Ground & currentSubject, int row, int col ) {
    for( int i = row - 1 ; i < row + 2; i ++ ){
        for( int j = col - 1 ; j < col + 2; j++ ){
            if( i == row && j == col){}
            else{
                //cout << "Tile[i][j]: " << (tiles[i][j])->getChar() << endl;
                shared_ptr<Ground> neighbour = dynamic_pointer_cast<Ground> ( tiles[i][j] );
                currentSubject.attach( neighbour );
            }
        }
    }
}

void Floor::attachObservers( std::shared_ptr<TextDisplay> td ){
    int row = 0;
    int col = 0;
    for( auto r : tiles){
        for( auto tile : r ){
            //cout << "row, col: " << row << " " << col << endl;
            shared_ptr<Ground> groundTile = dynamic_pointer_cast< Ground >( tile);
            if( groundTile != nullptr ){
                addNeighbours( * groundTile, row, col );
                groundTile->attach( td );
            }
            td->notify( tile );
            col++;
        }
        col = 0;
        row++;
    }
    row = 0;
}


Floor::Floor( std::shared_ptr<TextDisplay> td, std::istream & in, std::shared_ptr<Player> p ) {
    string line = "";
    char c;
    for( int row = 0; row < 25; row++ ){
        vector<shared_ptr<Tile> > t;
        tiles.push_back(t);
        getline( in, line );
        if( line == "" ){
            getline( in, line );
        }
        for( int col = 0; col < 79; col++ ){
            c = line[col];
            addTile( row, col, c, p );
        }
    }
    attachObservers( td );
    checkDragonGold();
}


void Floor::getChamber(int & chamIndex, RandomGeneration & rng, int & NUM_CHAMBERS, const int player ) { //gets the chamber number between 0 and 4 
    chamIndex = rng.randomInt( NUM_CHAMBERS );
    while( chamIndex == player ){ //this is to make sure the stairs aren't in the same chamber as the player. Default value is -1.
        chamIndex = rng.randomInt( NUM_CHAMBERS );
    }
}

std::shared_ptr<Ground> Floor::generateLocation( int & chamIndex, int & tileIndex, vector<vector<shared_ptr<Ground> > > & chambers, 
    RandomGeneration & rng, int & NUM_CHAMBERS, const int player ){ 
    
    getChamber( chamIndex, rng, NUM_CHAMBERS, player );

    int NUM_TILES = chambers[chamIndex].size(); 
    while( NUM_TILES == 0 ){ //this is to make sure we're not trying to generate in a chamber that is already full ... kinda an edge case, but I digress. 
        if( chamIndex == 0 ){
            chambers.erase( chambers.begin() ); //for some reason calling erase on chambers.begin() + 0 doesn't work so I just check if it's zero first.
        } else {
            chambers.erase( chambers.begin() + chamIndex );
        }
        NUM_CHAMBERS--;
        getChamber( chamIndex, rng, NUM_CHAMBERS, player );
        NUM_TILES = chambers[chamIndex].size(); 
        if( NUM_CHAMBERS == 0 ) return nullptr;
    }

    tileIndex = rng.randomInt( NUM_TILES );

    return chambers[chamIndex][tileIndex];
}

void Floor::removeTile( int & chamIndex, int & tileIndex, vector<vector<shared_ptr<Ground> > > & chambers){ //we remove tiles that already have something on them 
    //this way we won't generate twice on a tile.
    if( tileIndex == 0 ){
        chambers[chamIndex].erase( chambers[chamIndex].begin() );
    } else{
        chambers[chamIndex].erase( chambers[chamIndex].begin() + tileIndex );
    }
}

std::shared_ptr<Ground> Floor::randomDragon( std::shared_ptr<DragonGold> dg, std::shared_ptr<Ground> tile, RandomGeneration & rng  ){
    vector<shared_ptr<Ground> > ground;
    int upper;
    int location;
    for( auto t : tile->neighbours ){
        if( t != nullptr ){ 
            if(t->type == State::Ground){
                ground.push_back(t);
            }
         }
    }
    upper = ground.size();
    if( upper != 0 ){
        location = rng.randomInt( upper );
    } else {
        throw NoSpace( "No ground available" );
    }
    auto d = make_shared<Dragon>();
    d->setGold( dg );
    dg->setDragon( d );
    auto dragonTile = ground[location];
    dragonTile->setEnemy(d);
    return dragonTile;
}

void Floor::removeDragonTile(int & chamIndex, vector<vector<shared_ptr<Ground> > > & chambers, shared_ptr<Ground> DragonTile ){
    int index = 0;
    for( auto tile : chambers[chamIndex]){
        if( tile == DragonTile){
            if( index == 0){
                chambers[chamIndex].erase( chambers[chamIndex].begin() );
            } else {
                chambers[chamIndex].erase( chambers[chamIndex].begin() + index );
            } 
        } else {
            index++;
        }
    }
}

void Floor::generate( std::shared_ptr<Player> p, int DIFFICULTY, int NUM_CHANGE ){
    //cout << "@ Floor generate" << endl;
    int NUM_CHAMBER = 5; //was going to set these to const but if we want we can add a difficulty modifier that'll change these values 
    int NUM_ENEMIES = 20 + 2*NUM_CHANGE;
    int NUM_POTIONS = 10 + NUM_CHANGE;
     int NUM_GOLD = 10 + NUM_CHANGE;
    int chamIndex, tileIndex;
    vector<vector<shared_ptr<Ground> > > chambers;

    for( int i = 0; i < NUM_CHAMBER; i++){
        vector<shared_ptr<Ground> > chamber;
        chambers.push_back( chamber );
    }

    for( int i = 0; i < NUM_CHAMBER; i ++) { //this adds all the ground floors to their respective chamber vector
        for(auto r : tiles ){
            for( auto tile : r ){
                if( tile->type == State::Ground ){
                    auto ground = static_pointer_cast< Ground >( tile );
                    if( ground->getChamber() == i ){
                        chambers[i].push_back( ground );
                    }
                }
            }
        }
    }

    RandomGeneration rng = RandomGeneration();
    rng.setSeed();

    auto playerTile = generateLocation( chamIndex, tileIndex, chambers, rng, NUM_CHAMBER ); //adds the player to the board. 
    playerTile->setPlayer( p );
    p->setLocation( playerTile.get() );
    player = playerTile;
    removeTile( chamIndex, tileIndex, chambers );
    
    auto stairTile = generateLocation( chamIndex, tileIndex, chambers, rng, NUM_CHAMBER, chamIndex ); //adds stairs
    stairTile->setStair( true );
    removeTile( chamIndex, tileIndex, chambers );

    int toSpawn = NUM_POTIONS + NUM_GOLD + NUM_ENEMIES; // for the for-loop. was too lazy to write three for loops so used cases instead
    NUM_GOLD += NUM_POTIONS; //setting all the probabilities 
    NUM_ENEMIES += NUM_GOLD;

    int RH = 1 + DIFFICULTY;  
    int BA = 1 + DIFFICULTY; 
    int BD = 1 + DIFFICULTY; 
    int PH = 1 + 2*DIFFICULTY; 
    int WA = 1 + 2*DIFFICULTY; 
    int WD = 1 + 2*DIFFICULTY;
    RandomPotion rpg = RandomPotion( RH, BA, BD, PH, WA, WD);
    rpg.setSeed();
    int small = 2 + 2*DIFFICULTY; 
    int dragon = 1 + 2*DIFFICULTY;
    int normal = 5 + DIFFICULTY; ; 
    RandomGold rgg = RandomGold( small, dragon, normal );
    rgg.setSeed();
    int H = 4 + DIFFICULTY; 
    int W = 3 + DIFFICULTY; 
    int E = 5 + DIFFICULTY; 
    int O = 2 + 2*DIFFICULTY; 
    int M = 2 + DIFFICULTY; 
    int L = 2 + 2*DIFFICULTY; 
    RandomEnemy reg = RandomEnemy( H, W, E, O, M, L);
    reg.setSeed();

    for( int i = 0; i < toSpawn; i++ ){
        auto tile = generateLocation( chamIndex, tileIndex, chambers, rng, NUM_CHAMBER );
        if( tile == nullptr ) return;
        if( i < NUM_POTIONS ){
            auto potion = rpg.get();
            tile->setPotion( potion );
        }else if( i <  NUM_GOLD){
            auto gold = rgg.get();
            auto dg = dynamic_pointer_cast< DragonGold> (gold);
            if( dg != nullptr ){
                try{
                auto dragonTile = randomDragon( dg, tile, rgg ); //whenever we create a gold we have to create a dragon.
                } catch( NoSpace ) {
                    i--;
                    break;
                }
                removeDragonTile( chamIndex, chambers, tile );
                tile->setDragonGold( gold );
            } else {
                tile->setGold( gold );
            }
        }else if( i < toSpawn ){
            auto enemy = reg.get();
            tile->setEnemy( enemy );
        }
        removeTile( chamIndex, tileIndex, chambers );
    }
    //cout << reg.getCount() << endl;
}


// call notify() for each tile
void Floor::notify(){
  for (auto x : tiles){
    for (auto y : x){
      y->notify();
    }
  }
}

Floor::~Floor(){
    for(auto r : tiles ){
        for( auto tile : r ){
            tile->clear();
        }
        r.clear();
    }
    tiles.clear();
    player = nullptr;
}

// try to move enemy to a random tile or attack
// a player tile if there is one near it
string Floor::moveEnemies(){
    message = "";
    for (auto x : tiles){
    for (auto y : x){
        try{
            string temp = y->moveEnemy();
            if (temp != ""){  
                message += temp + "\n";
            }
        }
        catch(InvalidMove e){
            // do nothing
        }
    }
  }
  notify();
  return message;
}


void Floor::setPlayerPointer(std::shared_ptr<Player> p ){
    p->setLocation( player.get() );
}

