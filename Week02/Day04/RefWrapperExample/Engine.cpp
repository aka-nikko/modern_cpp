#include "Engine.h"

Engine::Engine(int horsepower, EngineType type):
    _horsepower(horsepower), _engineType(type){}
    
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_horsepower: " << rhs._horsepower
       << " _engineType: " << static_cast<int>(rhs._engineType);
    return os;
}
