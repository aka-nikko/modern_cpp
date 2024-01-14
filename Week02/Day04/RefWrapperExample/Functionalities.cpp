#include"Functionalities.h"

void CreateObjects(CarContainer& carData, EngineContainer& engineData){
    engineData[0] = std::make_shared<Engine>(
        201, 
        EngineType::PETROL
    );
    carData[0]=std::make_shared<Car>(
        101,
        "Dzire",
        750000.0f,
        engineData[0]
    );

    engineData[1] = std::make_shared<Engine>(
        202, 
        EngineType::HYBRID
    );
    carData[1]=std::make_shared<Car>(
        102,
        "BMW",
        12000000.0f,
        engineData[1]
    );

    engineData[2] = std::make_shared<Engine>(
        203,
        EngineType::DIESEL
    );
    carData[2]=std::make_shared<Car>(
        103,
        "Mahindra",
        750000.0f,
        engineData[2]
    );
}

void DisplayObjects(CarContainer & carData){
    for (const auto& car : carData) {
        std::cout << *car << std::endl;
    }
}