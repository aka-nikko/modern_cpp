#include"Functionalities.h"
#include<functional>

void performOperation(std::function<void(CarContainer&)> operation, CarContainer& data) {
    operation(data);
}

int main(){
    CarContainer data;
    CreateObejects(data);

    // Displaying all cars
    std::cout << "All Cars:\n";
    for (const auto& car : data) {
        std::cout << *car << "\n";
    }

    // Creating a partial function with price parameter fixed to 12000
    try{
        auto partialCountCarsFunction = std::bind(CountCarsMatchingCondition, std::placeholders::_1, 12000);
        performOperation(partialCountCarsFunction, data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    // Calculate average horsepower
    try{
        performOperation(AverageHorsePower, data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    // Calculate combined insurance cost
    try{
        performOperation(CombinedInsuranceCost, data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    // Get unique manufacturers with horsepower > 150 and resale value > 25000
    try{
        performOperation(UniqueManufacturersWithCondition, data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    return 0;
}