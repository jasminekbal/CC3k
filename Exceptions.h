#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_
#include <string>

//some exceptions we might want to throw. 
//we also might want to make these different files

class Exceptions{
    std::string message;
    public: 
    Exceptions(std::string message );
    std::string getMessage();
};

class badCommand: public Exceptions{ // in case the player tries to move to a wall, or use a potion that doesn't exist or something
    public:
    badCommand( std::string message );
};

class noFile: public Exceptions{ //if the input file for the floor doesn't exist
    public:
    noFile( std::string message );
};

class dragonStillAlive: public Exceptions{ //if you step on a dragon gold
    public:
    dragonStillAlive( std::string message );
};

#endif
