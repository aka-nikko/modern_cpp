#include"Functionalities.h"
#include"PetrolCar.h"
#include"DieselCar.h"
#include"EvCar.h"
#include"HybridCar.h"

void CreateObjects(Container& data){

    //Petrol Car
    data.emplace_back(
        std::make_shared<PetrolCar>(101, "City", 1400000.0f, VehicleType::PERSONAL, 43)
    );
    data.emplace_back(
        std::make_shared<PetrolCar>(102, "Dzire", 9000000.0f, VehicleType::PERSONAL, 35)
    );

    //Diesel Car
    data.emplace_back(
        std::make_shared<DieselCar>(201, "Mahindra", 15000000.0f, VehicleType::PERSONAL, 35)
    );
    data.emplace_back(
        std::make_shared<DieselCar>(202, "Toyota", 4500000.0f, VehicleType::PERSONAL, 65)
    );

    //Electric Car
    data.emplace_back(
        std::make_shared<EvCar>(301, "SUV", 16000000.0f, VehicleType::PERSONAL, 85)
    );
    data.emplace_back(
        std::make_shared<EvCar>(302, "Sedan", 7800000.0f, VehicleType::PERSONAL, 94)
    );

    //Hybrid Car
    data.emplace_back(
        std::make_shared<HybridCar>(401, "City", 14000000.0f, VehicleType::PERSONAL, 34, 60)
    );
    data.emplace_back(
        std::make_shared<HybridCar>(402, "Dzire", 9000000.0f, VehicleType::PERSONAL, 54, 70)
    );
}

void DisplayObjects(const Container& data) {
    for (const auto& vehicle : data) {
        // std::cout << *vehicle << std::endl;

        // vehicle->display();

        if(auto petrol=std::dynamic_pointer_cast<PetrolCar>(vehicle)){
            std::cout<<*petrol<<std::endl;
        }else if(auto diesel=std::dynamic_pointer_cast<DieselCar>(vehicle)){
            std::cout<<*diesel<<std::endl;
        }else if(auto elec=std::dynamic_pointer_cast<EvCar>(vehicle)){
            std::cout<<*elec<<std::endl;
        }else if(auto hybrid=std::dynamic_pointer_cast<HybridCar>(vehicle)){
            std::cout<<*hybrid<<std::endl;
        }

    }
}