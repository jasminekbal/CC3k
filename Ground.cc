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
Ground::Ground(int row, int col, State t, int room, std::shared_ptr<Enemy> e, std::shared_ptr<Potion> po, std::shared_ptr<Gold> g, std::shared_ptr<Player> pl): Tile(row,col,t){
    chamber = room;
    //td = make_shared<TextDisplay>();

    // Ground = '.', Stairs = '\', Passageway = '#', Enemy = enemy.getChar(), Player = '@', Potion = 'P', Gold = 'G'
    if (type == State::Ground){
        c='.';
    }
    else if (type == State::Stairs){
        c='\\';
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
    else if (type == State::DragonGold){
        gold = g;
        c='G';
    }
}

Ground::~Ground(){}

void Ground::clear(){
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
  }
  else if (type==State::Door){
  }
  tile.c = '#';
  c = '@';
  player = tile.player;
  player->setLocation( this );
  return "";
}

string Ground::doorHelper(Ground & tile){
  string message;
  switch( type ){
    case State::Ground: 
    {
      type = State::Player;
      player = tile.player;
      player->setLocation( this );
      c = '@';
      tile.c = '+';
      tile.player = nullptr;
      return "";
    }
      break;
    case State::Passageway:
    {
      player = tile.player;
      player->setLocation( this );
      c = '@';
      tile.c = '+';
      tile.player = nullptr;
      return "";
    }
      break;
    case State::Enemy:
      message = onAttack( tile );
      break;
    case State::Gold:
      message = collectGold( tile );
      break;
    case State::DragonGold:
      message = collectGold( tile );
      tile.type = State::Door;
      tile.c = '+';
      break;
    case State::Potion:
      message = usePotion( tile );
      break;
    default:
      throw Exceptions( "We shouldn't be here, doorHelper ");
  }
  return message;
}

string Ground::enemyHelper(Ground & tile){
  if (type==State::Ground || type == State::Enemy ){
    if( enemy == nullptr ) {
      enemy = tile.enemy;
      c = enemy->getChar();
      tile.type = State::Ground;
      tile.c = '.';
      tile.enemy = nullptr;
      return "";
    } else {
      throw InvalidMove( "Enemy tried to walk into one another" );
    }
  }
  else if ( type==State::Player || type == State::DragonGold ){
    if( player != nullptr ){
      if( !(tile.enemy->getHasAttacked()) ){
        tile.enemy->setHasAttacked( true );
        if ( (tile.enemy)->attack( player.get() ) ){  // true if attack landed
          // tile remains enemy type
          return "You have been attacked by an enemy!";
        } else {
          return "An enemy tried to attack you but they failed!";
        }
      } else {
        return "";
      }
    } else {
      throw InvalidMove{"Enemy tried to move to an occupied tile"};
    }
  }
  else{
    throw InvalidMove{"Enemy tried to move to an occupied tile"};
  }
}


string Ground::onAttack( Ground & tile ){
  if ( (tile.player)->attack( enemy.get() ) ){ // true if attack went through
    if (!(enemy->getHp())){ // true if enemy died
      gold = enemy->onDeath();
      if( gold != nullptr ){
        try{
          tile.player->collectGold(gold);
          type = State::Ground;
          c = '.';
        } catch(CantCollect e){  
          type = State::Gold;
          c = 'G';
          gold->setCanCollect(1);
        }
      } else {
        type = State::Ground;
        c = '.';
      }
      enemy = nullptr;
      return "You killed your enemy!";
    } else{
      // if player attacks enemy and enemy survives,
      // enemy will become hostile
      enemy->makeHostile();
      return "You hit your enemy!";
    }
  } else{
      // enemy will become hostile
      enemy->makeHostile();
      return "You attacked but you missed :(";
  } // give message
}


string Ground::usePotion( Ground & tile ){
  string message = "You used a " + potion->getType() + " potion";
  potion->usePotion(tile.player);
  // delete Potion
  potion = nullptr;
  type = State::Ground;
  c = '.';
  string secondMessage = move( tile );
  return message + secondMessage;
}

string Ground::collectGold( Ground & tile ){
  try{
    tile.player->collectGold(gold);
    string s = (gold->getChange() > 1) ? "s" : "";
    string message = "You collected " + to_string(gold->getChange()) + " coin" + s ; //correct grammar for bonus marks? 
    // delete Gold
    gold = nullptr;
    type = State::Ground;
    c = '.';
    string secondMessage = move( tile );
    return message + secondMessage;
  }
  catch (CantCollect e){
    player = tile.player;
    c = '@';
    player->setLocation( this );
    tile.player = nullptr;
    return "cannot collect gold that belongs to a living dragon";
  } catch (DragonStillAlive e) {
    player = tile.player;
    c = '@';
    player->setLocation( this );
    tile.player = nullptr;
    return e.getMessage();
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
  string message;
  switch( type ){
    case State::Ground: 
    {
      type = State::Player;
      player = tile.player;
      c = '@';
      player->setLocation( this );
      tile.type = State::Ground;
      tile.c = '.';
      tile.player = nullptr;
      return "";
    }
    case State::Door:
    {
      player = tile.player;
      player->setLocation( this );
      c = '@';
      tile.c = '.';
      tile.type = State::Ground;
      tile.player = nullptr;
      return "";
    }
    case State::Enemy:
      message = onAttack( tile );
      break;
    case State::Gold:
      message = collectGold( tile );
      break;
    case State::DragonGold:
      message = collectGold( tile );
      tile.c = '.';
      tile.type = State::Ground;
      break;
    case State::Potion:
      message = usePotion( tile );
      break;
    default:
      throw Exceptions( "We shouldn't be here, groundPlayerHelper");
  }
  return message;
}

// moves players and enemies as well as handling all interactions between objects and characters
// TODO: move needs a way to update or return the user's message from attack, usepotion, getgold, etc.
// TODO: errortrap still required!!!
string Ground::move(Ground & tile){   // throws invalidMove exception if theres an error
  string message;
  switch( tile.type ){
    case State::DragonGold:
    {
      message = playerHelper( tile );
      if( tile.gold->getCanCollect() ){
        player->collectGold( tile.gold );
        c = '@';
        type = State::Player;
        player->setLocation( this );
      } else {
        tile.type = State::DragonGold;
        tile.c = 'G';
        if( tile.player == nullptr ){ //if the character successfully moves
          c = '@';
        } else { //if the character doesn't leave the tile, it attacked an enemy
          tile.c = '@';
          c = enemy->getChar();
        }
      }
    }
      break;
    case State::Player:
      message = playerHelper(tile);
      break;
    case State::Enemy:
      message = enemyHelper(tile);
      break;
    case State::Door:
      message = doorHelper(tile);
      break;
    case State::Passageway:
      message = passageWayHelper( tile );
      break;
    default: 
      throw Exceptions( "We shouldn't be here, Ground move ");
  }
  return message;
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
void Ground::attach(shared_ptr<Ground> g) { neighbours.push_back(g); }

void Ground::attach(std::shared_ptr<TextDisplay> td){ this->td = td; }

// notifies observers
void Ground::notify(){ 
  for (auto &ob : neighbours) {
    if( ob != nullptr ){
      ob->notify( make_shared<Ground>(*this) );
    }
  }
  td->notify(make_shared<Tile>(*this));
}

// called so that this tile knows what its neighbours are up tos
void Ground::notify(shared_ptr<Ground> whoNotified){ // check if there's a player near an enemy
  if (enemy) {
    type = State::Enemy;   // update enemy state
    enemy->setHasAttacked( false );
  }
  playerNearEnemy = nullptr; // reset for now
  // check if there's a player near an enemy
  if (type == State::Enemy || (type == State::DragonGold && gold->getCanCollect()==0)){
    for (int x=0;x<neighbours.size(); x+=1){
      if(neighbours[x] != nullptr ){
        if( neighbours[x]->player != nullptr ){ // found a nearby player
          playerNearEnemy = neighbours[x];
          return;
        }
      }
    } 
  }
}

// setters
void Ground::setStair( bool b ){
  if( b ){
    type = State::Stairs;
    c = '\\';
    td->notify( make_shared<Tile>(*this));
  } else {
    type = State::Ground;
    c = '.';
    td->notify( make_shared<Tile>(*this));
  }
}

// calls move on correct neighbour
string Ground::movePlayer(int dir){
  if (neighbours[dir]){
    string message = (*neighbours[dir]).move(*this);
    notify(); // notify neighbours of movement
    (*neighbours[dir]).notify();
    return message;
  }
  else{
    throw WallMove{"You hit a wall"};
  }
}

// moves enemy if there's an enemy on this tile
string Ground::moveEnemy(){
  if (type == State::Passageway) throw InvalidMove{"Not an enemy"};
  else if (type==State::Door) throw InvalidMove{"Not an enemy"};
  // dragon attacks when someone's near its gold and it's alive
  else if( type == State::DragonGold ){
    if( playerNearEnemy && gold->getCanCollect() == 0 ){
      auto dragonGold = static_pointer_cast<DragonGold>( gold );
      if( !( dragonGold->getHasAttacked() ) ){
        dragonGold->setHasAttacked( true );
        if (dragonGold->attack( (playerNearEnemy->player).get() )) return "You were attacked by a dragon for trying to take its gold!!!";
        else return "A dragon tried to attack you for being too close to its gold, but it missed. What a loser.";
      } 
    } 
  }
  else if (type==State::Enemy){
    // check if there's a player nearby that we need to attack
    if (playerNearEnemy && enemy->isHostile()){
      return (*playerNearEnemy).move(*this);
    }
    // otherwise choose random direction for enemy to move in
    else{
      // check if dragon
      if (enemy->getChar() == 'D') throw InvalidMove{"Dragon doesn't need to move"};
      return randomMove();
    }
  } 
  //cout << "Not an enemy";
  throw InvalidMove{"Not an enemy"};
}

// chooses a random tile that enemy can move to
string Ground::randomMove(){
  int count = 0;
  // count is there so that enemy does not get stuck in infinite loop
  while(count < 10 ){
    string message;
    try{
      int random = rand() % 8;
      if (neighbours[random] == nullptr ){
        throw InvalidMove{"Enemy tried to move to a wall"};
      }
      else if(!(enemy->isHostile()) && (neighbours[random]->getInfo()).state==State::Player) {
        throw InvalidMove{"Enemy accidentally tried to attack a player"};
      }
      else {
        //cout << "trying to move" << endl;
        message =  (*(neighbours[random])).move(*this);
        //cout << "moved successfully " <<endl;
        return message;
      }
    }
    catch(InvalidMove e){
      //cout << "I caught " << e.getMessage() << endl;
    }
    count+=1;
  }
  return "";
}


void Ground::setPlayer( std::shared_ptr<Player> p){ 
  player = p; 
  c = '@';
  type = State::Player;
  notify();
}

void Ground::setEnemy( std::shared_ptr<Enemy> e){ 
  enemy = e;
  c = e->getChar();
  type = State::Enemy;
  td->notify( make_shared<Tile>( * this ) );
}

void Ground::setPotion( std::shared_ptr<Potion> p){ 
  potion = p; 
  c = 'P';
  type = State::Potion;
  td->notify( make_shared<Tile>( * this ) );
}

void Ground::setGold( std::shared_ptr<Gold> g){ 
  gold = g; 
  c = 'G';
  type = State::Gold;
  td->notify( make_shared<Tile>( * this ) );
}

void Ground::setDragonGold( std::shared_ptr<Gold> g){ 
  gold = g; 
  c = 'G';
  type = State::DragonGold;
  td->notify( make_shared<Tile>( * this ) );
}

