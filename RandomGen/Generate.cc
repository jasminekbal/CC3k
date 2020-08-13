#include "../Floor.h"
#include "RandomGeneration.h"
#include "RandomEnemy.h"
#include "RandomPotion.h"
#include "RandomGold.h"
#include "../Info.h"
#include "../Ground.h"
#include "../Tile.h"
#include "../Characters/Player.h"
#include "../Enemies/Enemy.h"
#include "../Items/Gold.h"
#include "../Items/Potion.h"
#include "../Items/DragonGold.h"
#include "../Exceptions.h"
#include <vector>
#include <memory>

using namespace std;

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
    auto neighbours = tile->getNeighbours();
    vector<shared_ptr<Ground> > ground;
    int upper;
    int location;
    for( auto tile : neighbours ){
        if( tile != nullptr ){ 
            if(tile->type == State::Ground){
                ground.push_back(tile);
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

void Floor::generate( std::shared_ptr<Player> p ){
    int NUM_CHAMBER = 5; //was going to set these to const but if we want we can add a difficulty modifier that'll change these values 
    int NUM_ENEMIES = 20;
    int NUM_POTIONS = 10;
    int NUM_GOLD = 10;
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
                    if( ground->chamber == i ){
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
    p->setLocation( playerTile );
    removeTile( chamIndex, tileIndex, chambers );
    
    auto stairTile = generateLocation( chamIndex, tileIndex, chambers, rng, NUM_CHAMBER, chamIndex ); //adds stairs
    stairTile->setStair( true );
    removeTile( chamIndex, tileIndex, chambers );

    int toSpawn = NUM_POTIONS + NUM_GOLD + NUM_ENEMIES; // for the for-loop. was too lazy to write three for loops so used cases instead
    NUM_GOLD += NUM_POTIONS;
    NUM_ENEMIES += NUM_GOLD;

    int RH = 1;  //setting all the probabilities 
    int BA = 1; 
    int BD = 1; 
    int PH = 1; 
    int WA = 1; 
    int WD = 1; 
    RandomPotion rpg = RandomPotion( RH, BA, BD, PH, WA, WD);
    rpg.setSeed();
    int small = 2; 
    int dragon = 1; 
    int normal = 5; 
    RandomGold rgg = RandomGold( small, dragon, normal );
    rgg.setSeed();
    int H = 4; 
    int W = 3; 
    int E = 5; 
    int O = 2; 
    int M = 2; 
    int L = 2; 
    RandomEnemy reg = RandomEnemy( H, W, E, O, M, L);
    reg.setSeed();

    for( int i = 0; i < toSpawn; i++ ){
        auto tile = generateLocation( chamIndex, tileIndex, chambers, rng, NUM_CHAMBER );
        
        if( i < NUM_POTIONS ){
            auto potion = rpg.get();
            tile->setPotion( potion );
        } else if( i <  NUM_GOLD){
            auto gold = rgg.get();
            auto dg = dynamic_pointer_cast< DragonGold> (gold);
            if( dg != nullptr ){
                try{
                auto dragonTile = randomDragon( dg, tile, rgg ); //whenever we create a gold we have to create a dragon. 
                //Technically we should test to see if there's even an available tile for the dragon, in case we spawn a dragon gold
                //in the middle of a bunch of enemies. If I have time I'll add that, but it's not very likely to happen so I'll just pretend it won't for now
                //this function remains to be created. Task for tomorrow I think. 
                } catch( NoSpace ) {
                    i--;
                    break;
                }
                removeDragonTile( chamIndex, chambers, tile );
            }
            tile->setGold( gold );
        } else{
            auto enemy = reg.get();
            tile->setEnemy( enemy );
        }
        removeTile( chamIndex, tileIndex, chambers );
    }
}

