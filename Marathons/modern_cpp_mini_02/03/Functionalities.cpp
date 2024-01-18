#include"Functionalities.h"

void CreateCarObjects(Container& data, EngineContainer& engineData){
    engineData.emplace_back(
        std::make_shared<Engine>(
            "1001"
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "101",
            "Audi",
            12000.0f,
            CarCategory::SEDAN,
            engineData.back()
        )
    );

    engineData.emplace_back(
        std::make_shared<Engine>(
            "1002"
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "102",
            "BMW",
            2400000.0f,
            CarCategory::HATCHBACK,
            engineData.back()
        )
    );

    engineData.emplace_back(
        std::make_shared<Engine>(
            "1003"
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "103",
            "Honda",
            1200000.0f,
            CarCategory::SEDAN,
            engineData.back()
        )
    );
}

void CreateEvTruckObjects(Container& data){
    data.emplace_back(
        std::make_shared<EvTruck>(
            "201",
            "Honda",
            1200000.0f,
            56
        )
    );
    data.emplace_back(
        std::make_shared<EvTruck>(
            "202",
            "Maruti",
            4300000.0f,
            87
        )
    );
    data.emplace_back(
        std::make_shared<EvTruck>(
            "202",
            "Mahindra",
            4500000.0f,
            24
        )
    );
}

void DisplayObjects(Container & data){
    for(auto vehicle : data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
            std::cout<<*mycar<<std::endl;
        }else if(auto mytruck=std::dynamic_pointer_cast<EvTruck>(vehicle)){
            std::cout<<*mytruck<<std::endl;
        }
    }
}

std::shared_ptr<Vehicle> SearchVehicleById(Container & data, std::string id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    for(auto vehicle : data){
        if(vehicle->id()==id){
            return vehicle;
        }
    }

    throw std::runtime_error("Vehicle With Given ID Not Found!");
}

int CountOfGivenVehicle(Container &data, std::string searchVehicle){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    int carCount=0;
    int evTruckCount=0;

    if(searchVehicle=="Car"){
        for(auto vehicle : data){
            if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
                carCount++;
            }
        }
        return carCount;
    }

    if(searchVehicle=="EvTruck"){
        for(auto vehicle : data){
            if(auto mytruck=std::dynamic_pointer_cast<EvTruck>(vehicle)){
                evTruckCount++;
            }
        }
        return evTruckCount;
    }

    throw std::runtime_error("Vehicle Not Found!");
}

float AveragePriceOfGivenVehicle(Container &data, std::string searchVehicle){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    int carCount=0;
    int evTruckCount=0;
    float carPrice=0.0f;
    float evTruckPrice=0.0f;

    if(searchVehicle=="Car"){
        for(auto vehicle : data){
            if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
                carCount++;
                carPrice=carPrice+mycar->price();
            }
        }
        return carPrice/carCount;
    }

    if(searchVehicle=="EvTruck"){
        for(auto vehicle : data){
            if(auto mytruck=std::dynamic_pointer_cast<EvTruck>(vehicle)){
                evTruckCount++;
                evTruckPrice=evTruckPrice+mytruck->price();
            }
        }
        return evTruckPrice/evTruckCount;
    }

    throw std::runtime_error("Vehicle Not Found!");
}

Container RegistrationChargeCondition(Container &data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    Container result;

    for(auto vehicle : data){
        if(vehicle->CalculateRegistrationCharges()>0&&vehicle->CalculateRegistrationCharges()<5000){
            result.emplace_back(vehicle);
        }
    }

    return result;
}
