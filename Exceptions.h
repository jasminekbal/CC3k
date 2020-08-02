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

class badCommand: public Exceptions{
    public:
    badCommand( std::string message );
};

class noFile: public Exceptions{
    public:
    noFile( std::string message );
};

class dragonStillAlive: public Exceptions{
    public:
    dragonStillAlive( std::string message );
};

#endif
