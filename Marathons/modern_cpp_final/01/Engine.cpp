#include"Engine.h"

Engine::Engine(std::string id, size_t horsePower, EngineType engineType, 
                float engineCapacity, float engineTorque):
    _id(id), _horsePower(horsePower), _engineType(engineType), 
    _engineCapacity(engineCapacity) {
        if(engineTorque>20&&engineTorque<150){
            _engineTorque=engineTorque;
        }else{
            std::cout<<"Torque should be Between 20 - 150"<<std::endl;
        }
    }

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_id: " << rhs._id
       << " _horsePower: " << rhs._horsePower
       << " _engineType: " << static_cast<int>(rhs._engineType)
       << " _engineCapacity: " << rhs._engineCapacity
       << " _engineTorque: " << rhs._engineTorque;
    return os;
}
