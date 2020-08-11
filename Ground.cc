#include "Ground.h"
#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include "Enemy.h"
#include "Potion.h"
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

// moves players and enemies as well as handling all interactions between objects and characters
// TODO: move needs a way to update or return the user's message from attack, usepotion, getgold, etc.
// TODO: errortrap still required!!!
void Ground::move(Ground & tile){   // throws invalidMove exception if theres an error
  if (tile.type == State::Player){
    if (tile.type==State::Ground){
      player = tile.player;
      player->setLocation(make_shared<Ground>(*this));
      c = '@';
    }
    else if (tile.type==State::Enemy){ // need to be able to exchange enemy w/ its gold if it dies
      if ((tile.player)->attack(*enemy)){ // true if enemy died 
        gold = enemy->onDeath();
        enemy = nullptr;
        type = State::Gold;
        c = 'G'; // '0' + gold->getChange();
      }
      else{
        // if player attacks enemy and enemy survives,
        // enemy will become hostile
        enemy->makeHostile();
      }
      // in this case, the tile remains a player type
      return;
    }
    else if (tile.type==State::Potion){
      potion->usePotion(tile.player);
      // delete Potion
      potion = nullptr;
      type = State::Ground;
      c = '.';
    }
    else if (tile.type==State::Gold){
     try{
      (tile.player)->collectGold(gold);
      // delete Gold
      gold = nullptr;
      type = State::Gold;
      c = '.';
     }
     catch (DragonStillAlive e){
       throw InvalidMove{"Cannot collect gold that belongs to a living dragon"};
     }
    }
  }
  else if (tile.type == State::Enemy){
    if (tile.type==State::Ground){
      enemy = tile.enemy;
      c = enemy->getChar();
    }
    else if (tile.type==State::Player){
      (tile.enemy)->attack(*player);
      // tile remains enemy type
      return;
    }
    else{
      throw InvalidMove{"Enemy tried to move to an occupied tile"};
    }
  }
  // second if statement changes the tile that is being moved away from
  if (tile.type == State::Door){
    
    if (tile.type==State::Ground){
      type = State::Player;
      player = tile.player;
      c = '@';
    }
    else if (tile.type==State::Passageway){
      player = tile.player;
      c = '@';
    }
    tile.c = '+';
  }
  else if (tile.type == State::Passageway){
    if (tile.type==State::Ground){
      type = State::Player;
      player = tile.player;
      c = '@';
    }
    else if (tile.type==State::Door){
      player = tile.player;
      c = '@';
    }
    tile.c = '#';
  }
  else{
    tile.type = State::Ground;
    tile.c = '.';
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
void Ground::notify(){  
  notifyObservers();
}

void Ground::notify(Subject & whoNotified){ // check if there's a player near an enemy
  playerNearEnemy = nullptr; // reset for now
  if (type == State::Enemy){
    for (int x=0;x<4; x+=1){
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

// moves enemy if there's an enemy on this tile
void Ground::moveEnemy(){
  if (type==State::Enemy){
    // check if there's a player nearby that we need to attack
    if (playerNearEnemy){
      // check if enemy type is hostile
      if (enemy->hostile()){
        move(*playerNearEnemy);
      }
      else{ // otherwise choose random direction for enemy to move in
        randomMove();
      }
    }
    // otherwise choose random direction for enemy to move in
    else{
      randomMove();
    }
  }
}

// chooses a random tile that enemy can move to
void Ground::randomMove(){
  while(1){
    try{
      int random = rand() % 4;
      if (random >= neighbours.size()){
        throw InvalidMove{"Enemy tried to move to an occupied tile"};
      }
      (*(neighbours[random])).move(*this);
      break;
    }
    catch(InvalidMove e){}
  }
}
