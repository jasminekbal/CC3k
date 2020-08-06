#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <iostream>

class Floor;
class TextDisplay;
class Player;

class Game{
    
    private:
    std::unique_ptr<Floor> f;
    std::shared_ptr<TextDisplay> td;
    std::shared_ptr<Player> p;

    int checkPlayerState(); // 0 for normal, 1 if player got to stairs, 2 if player died

    public:
    void tick();
    void newFloor();
    void newFloor( std::istream & input );

    std::string endGame( bool showScore );
    void moveCharacter( int dir );
    
    std::string interact( int dir );

}

#endif
