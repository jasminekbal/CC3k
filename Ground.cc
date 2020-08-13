#include "Ground.h"
#include "Characters/Player.h"
#include "Enemies/Enemy.h"
#include "Enemies/Dragon.h"
#include "Items/Potion.h"
#include "Items/Gold.h"
#include "Items/DragonGold.h"
#include "TextDisplay.h"
#include "Tile.h"
#include "Info.h"
#include "Exceptions.h"

using namespace std;

// Constructor sets type and pointer if there is one
Ground::Ground(int r, int c, State t, int room, std::shared_ptr<Enemy> e, std::shared_ptr<Potion> po, std::shared_ptr<Gold> g, std::shared_ptr<Player> pl): Tile(r,c,t){
    chamber = room;
    //td = make_shared<TextDisplay>();

    // Ground = '.', Stairs = '\', Passageway = '#', Enemy = enemy.getChar(), Player = '@', Potion = 'P', Gold = 'G'
    if (type == State::Ground){
        c='.';
    }
    else if (type == State::Stairs){
        c='\'';
    }
    else if (type == State::Passageway){
        c='#';
    }
    else if (type == State::Enemy){
        enemy = e;
        c=e->getChar();
    }
    else if (type == State::Player){
        player = pl;
        c='@';
    }
    else if (type == State::Potion){
        potion = po;
        c='P';
    }
    else if (type == State::Gold){
        gold = g;
        c='G';
    }
}

Ground::~Ground(){
  if( player != nullptr ){
    player->setLocation( nullptr);
  }
  if( enemy!= nullptr ){
    auto dragon = dynamic_pointer_cast<Dragon>(enemy);
    if (dragon != nullptr){
      dragon->setGold( nullptr );
    }
  }
  if( gold!= nullptr){
    auto dragonGold = dynamic_pointer_cast<DragonGold>(gold);
    if(dragonGold != nullptr ){
      dragonGold->setDragon( nullptr);
    }
  }
  player = nullptr;
  enemy = nullptr;
  playerNearEnemy = nullptr;
  potion = nullptr;
  gold = nullptr;
  neighbours.clear();
  td = nullptr;
}

string Ground::passageWayHelper(Ground & tile){
  if (type==State::Ground){
    type = State::Player;
    player = tile.player;
    c = '@';
  }
  else if (type==State::Door){
    player = tile.player;
    c = '@';
  }
  tile.c = '#';
  return "";
}

string Ground::doorHelper(Ground & tile){
  if (type==State::Ground){
    type = State::Player;
    player = tile.player;
    c = '@';
  }
  else if (type==State::Passageway){
    player = tile.player;
    c = '@';
  }
  tile.c = '+';
  return "";
}

string Ground::enemyHelper(Ground & tile){
  if (type==State::Ground){
    enemy = tile.enemy;
    c = enemy->getChar();
    tile.type = State::Ground;
    tile.c = '.';
    return "";
  }
  else if (type==State::Player){
    if (player->onAttacked(*(tile.enemy))){  // true if attack landed
      // tile remains enemy type
      return "You have been attacked by an enemy!";
    }
    else{
      return "An enemy tried to attack you but they failed!";
    }
  }
  else{
    throw InvalidMove{"Enemy tried to move to an occupied tile"};
  }
}

// handles movement of player
// changes player location for successful move
string Ground::playerHelper(Ground & tile){
  if (type==State::Stairs){
    (tile.player)->setIsStair(1);
    return "Next floor";
  }
  else{
    (tile.player)->setIsStair(0);
  }
  if (type==State::Ground){
    player = tile.player;
    player->setLocation(make_shared<Ground>(*this));
    c = '@';
    tile.type = State::Ground;
    tile.c = '.';
    tile.notify();
    notify(); // notify neighbours of movement
    player->setLocation(make_shared<Ground>(*this));
    return "";
  }
  else if (type==State::Enemy){ // need to be able to exchange enemy w/ its gold if it dies
    if (enemy->onAttacked(*(tile.player))){ // true if attack went through
      if (!(enemy->getHp())){ // true if enemy died
        gold = enemy->onDeath();
        try{
          tile.player->collectGold( gold );
        } catch(CantCollect e){  
          type = State::Gold;
          c = 'G';
          gold->setCanCollect(1);
        }
        enemy = nullptr;
        return "You killed your enemy!";
      }
      else{
        // if player attacks enemy and enemy survives,
        // enemy will become hostile
        enemy->makeHostile();
        return "You hit your enemy!";
      }
    }
    else{
      // enemy will become hostile
      enemy->makeHostile();
      return "You attacked but you missed :(";
    } // give message
  }
  else if (type==State::Potion){
    potion->usePotion(tile.player);
    // delete Potion
    potion = nullptr;
    type = State::Ground;
    c = '.';
    return "You used a " + potion->getType() + " potion";
  }
  else if (type==State::Gold){
    (player)->collectGold(gold);
    // delete Gold
    gold = nullptr;
    type = State::Gold;
    c = '.';
    return "You collected " + to_string(gold->getChange()) + " coins";
  }
  else if (type==State::DragonGold){
    try{
      (player)->collectGold(gold);
      // delete Gold
      gold = nullptr;
      type = State::Gold;
      c = '.';
    }
    catch (DragonStillAlive e){
      return "Cannot collect gold that belongs to a living dragon";
    }
  }
}

// moves players and enemies as well as handling all interactions between objects and characters
// TODO: move needs a way to update or return the user's message from attack, usepotion, getgold, etc.
// TODO: errortrap still required!!!
string Ground::move(Ground & tile){   // throws invalidMove exception if theres an error
  if (tile.type == State::Player){
    return playerHelper(tile);
  }
  else if (tile.type == State::Enemy){
    return enemyHelper(tile);
  }
  // second if statement changes the tile that is being moved away from
  if (tile.type == State::Door){
    return doorHelper(tile);
  }
  else if (tile.type == State::Passageway){
    return passageWayHelper(tile);
  }
} 

// empties tile and makes it a ground tile
// may not be used
void Ground::empty(){ 
    player = nullptr;
    enemy = nullptr;
    potion = nullptr;
    gold = nullptr;
    type = State::Ground;
}

bool Ground::getIsStair(){
    return type==State::Stairs;
}

// Subject overrides
Info Ground::getInfo() const{
    Info i;
    i.state = type;
    i.row = row;
    i.col = col;
    return i;
}

// Observer overrides
void Ground::attach(shared_ptr<Ground> g) { neighbours.emplace_back(g); }

void Ground::attach(std::shared_ptr<TextDisplay> td){ this->td = td; }

// notifies observers
void Ground::notify(){  
  for (auto &ob : neighbours) ob->notify( make_shared<Ground>(*this) );
  td->notify(make_shared<Tile>(*this));
}

// called so that this tile knows what its neighbours are up tos
void Ground::notify(shared_ptr<Ground> whoNotified){ // check if there's a player near an enemy
  Info i = whoNotified->getInfo();
  if (i.row == row-1 && i.col == col-1) neighbours[0] = whoNotified;
  else if (i.row == row-1 && i.col == col) neighbours[1] = whoNotified;
  else if (i.row == row-1 && i.col == col+1) neighbours[2] = whoNotified;
  else if (i.row == row && i.col-1 == col) neighbours[3] = whoNotified;
  else if (i.row == row && i.col+1 == col) neighbours[4] = whoNotified;
  else if (i.row == row+1 && i.col-1 == col) neighbours[5] = whoNotified;
  else if (i.row == row+1 && i.col == col) neighbours[6] = whoNotified;
  else if (i.row == row+1 && i.col+1 == col) neighbours[7] = whoNotified;

  recalculate();
}

void Ground::recalculate(){
  playerNearEnemy = nullptr; // reset for now
  // check if there's a player near an enemy
  if (type == State::Enemy || (type == State::DragonGold && gold->getCanCollect()==0)){
    for (int x=0;x<neighbours.size(); x+=1){
      Info i = neighbours[x]->getInfo();

      if (col == i.col && row == i.row){
        if (i.state == State::Player){  // found a nearby player
          playerNearEnemy = neighbours[x];
        }
        return;
      }
    }
  }
}

// setters
void Ground::setStair( bool b ){
  type = State::Stairs;
}

// calls move on correct neighbour
string Ground::movePlayer(int dir){
  return move(*neighbours[dir]);
}

// moves enemy if there's an enemy on this tile
string Ground::moveEnemy(){
  if (type==State::Enemy){
    // check if there's a player nearby that we need to attack
    if (playerNearEnemy){
      // check if enemy type is hostile
      if (enemy->isHostile()){
        return move(*playerNearEnemy);
      }
      else{ // otherwise choose random direction for enemy to move in
        return randomMove();
      }
    }
    // otherwise choose random direction for enemy to move in
    else{
      return randomMove();
    }
  }
}

// chooses a random tile that enemy can move to
string Ground::randomMove(){
  while(1){
    try{
      int random = rand() % 4;
      if (random >= neighbours.size()){
        throw InvalidMove{"Enemy tried to move to an occupied tile"};
      }
      return (*(neighbours[random])).move(*this);
    }
    catch(InvalidMove e){}
  }
}
