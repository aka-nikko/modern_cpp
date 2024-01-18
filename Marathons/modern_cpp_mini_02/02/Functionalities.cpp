#include"Functionalities.h"

void CreateObejects(CarContainer & data){
    data.emplace_back(
        std::make_shared<Car>(
            "Acura",
            "Integra",
            16919,
            16360.0f,
            2150.0f,
            100
        )
    );

    data.emplace_back(
        std::make_shared<Car>(
            "Acura",
            "RL",
            8588,
            29725.0f,
            42000.0f,
            210
        )
    );

    data.emplace_back(
        std::make_shared<Car>(
            "Audi",
            "A4",
            20397,
            22255.0f,
            23990.0f,
            150
        )
    );
}

void CountCarsMatchingCondition(CarContainer & data, float price){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    int count=0;
    for(auto car : data){
        if(car->horsePower()>100&&car->price()>price){
            count++;
        }
    }

    std::cout << "\nNumber of cars:"<< count << "\n";
}

void AverageHorsePower(CarContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float horsePowerSum=0;
    int count=0;
    for(auto car : data){
        if(car->price()>10000&&car->manufacturer()!="Audi"&&car->manufacturer()!="Cadillac"){
            horsePowerSum=horsePowerSum+car->horsePower();
            count++;
        }
    }

    std::cout << "\nAverage Horsepower : " << horsePowerSum/count << "\n";
}

void CombinedInsuranceCost(CarContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float insuranceCost=0.0f;
    for(auto car : data){
        if(car->manufacturer()=="BMW"){
            insuranceCost=insuranceCost+(0.2*car->price());
        }else{
            insuranceCost=insuranceCost+(0.08*car->price());
        }
    }

    std::cout << "\nCombined Insurance Cost: " << insuranceCost << "\n";
}

void UniqueManufacturersWithCondition(CarContainer& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is Empty!");
    }

    std::set<std::string> uniqueManufacturers;

    for (const auto& car : data) {
        if (car->horsePower() > 150 && car->resaleValue() > 25000) {
            uniqueManufacturers.insert(car->manufacturer());
        }
    }

    std::cout << "\nUnique Manufacturers :\n";
    for (const auto& manufacturer : uniqueManufacturers) {
        std::cout << manufacturer << "\n";
    }
}

