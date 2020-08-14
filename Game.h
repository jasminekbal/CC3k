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
    std::istream infile;
    
    int level;

    int checkPlayerState(); // 0 for normal, 1 if player got to stairs, 2 if player died

    public:
    Game(std::shared_ptr<Player> py);
    Game(std::shared_ptr<Player> py, std::istream &input);
    void tick();
    void newFloor();
    void newFloor( std::istream & input );

    std::string endGame( bool showScore );
    std::string moveCharacter( int dir );
    
};

#endif
