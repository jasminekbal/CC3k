#include "Exceptions.h"
#include <string>

Exceptions::Exceptions(std::string message ): message(message){}
    
std::string Exceptions::getMessage(){
    return message;
}

BadCommand::BadCommand( std::string message ): Exceptions(message){}

InvalidMove::InvalidMove( std::string message ): Exceptions(message){}

NoFile::NoFile( std::string message ): Exceptions(message) {}

DragonStillAlive::DragonStillAlive( std::string message ): Exceptions(message){}

NoSpace::NoSpace( std::string message ): Exceptions(message){}

CantCollect::CantCollect(std::string message):Exceptions(message){}
