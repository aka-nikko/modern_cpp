#include"Functionalities.h"

void CreateObjects(EngineContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    data[0]=std::make_shared<Engine>(
        "101",
        5000,
        EngineType::DIESEL,
        100.0f,
        30.0f
    );
    data[1]=std::make_shared<Engine>(
        "102",
        8000,
        EngineType::PETROL,
        130.0f,
        34.0f
    );
    data[2]=std::make_shared<Engine>(
        "103",
        1200,
        EngineType::HYBRID,
        67.0f,
        45.0f
    );
}

std::vector<EngineType> ReturnEngineTypesSatisfyingConditions(const EngineContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::vector<EngineType> result;
    
    for(auto& var : data){
        if(var->horsePower()>1000&&var->engineCapacity()>2.0f){
            result.emplace_back(var->engineType());
        }
    }

    if(result.empty()){
        throw std::runtime_error("Not Found!!");
    }
    return result;
}

void CheckIfAllTorqueAbove110(const EngineContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Check If All Engines Have Torque Above 110: ";
    std::cout<<std::boolalpha<<std::all_of(
        data.begin(),
        data.end(),
        [](const EnginePointer& ptr) { 
            return ptr->engineTorque()>110; 
        }
    )<<std::endl;
}

void CountInstancesOverGivenCapacity(const EngineContainer & data, float cap){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Count Of Engine Over Given Capacity: ";
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [&](const EnginePointer& ptr){
            return ptr->engineCapacity()>cap;
        }
    )<<std::endl;
}