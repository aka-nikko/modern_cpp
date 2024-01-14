#include "Engine.h"

Engine::Engine(std::string number, EngineType type, int horsepower, int torque):
    engineNumber(number), engineType(type), engineHorsepower(horsepower), engineTorque(torque){}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    std::string type;
    switch (static_cast<int>(rhs.engineType)){
    case 0:
        type="ICT";
        break;
    case 1:
        type="HYBRID";
        break;
    }
    os << "engineNumber: " << rhs.engineNumber
       << " engineType: " << type
       << " engineHorsepower: " << rhs.engineHorsepower
       << " engineTorque: " << rhs.engineTorque;
    return os;
}
