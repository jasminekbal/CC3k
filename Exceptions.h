#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_
#include <string>

//some exceptions we might want to throw. 
//we also might want to make these different files

class Exceptions{
    std::string message;
    public: 
    Exceptions(std::string message ): message(message){}
    std::string getMessage();
};

class BadCommand: public Exceptions{ // in case the player tries to move to a wall, or use a potion that doesn't exist or something
    public:
    BadCommand( std::string message );
};

class InvalidMove: public Exceptions{ // in case the player tries to move to a wall, or use a potion that doesn't exist or something
    public:
    InvalidMove( std::string message ): Exceptions(message){}
};

class NoFile: public Exceptions{ //if the input file for the floor doesn't exist
    public:
    NoFile( std::string message );
};

class DragonStillAlive: public Exceptions{ //if you step on a dragon gold
    public:
    DragonStillAlive( std::string message );
};

class NoSpace: public Exceptions{
    public:
    NoSpace( std::string message );
};


class CantCollect: public Exceptions{
    public:
    CantCollect(std::string message):Exceptions(message){}
};

#endif
