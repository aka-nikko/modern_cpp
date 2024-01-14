#include"Functionalities.h"
#include<functional>
#include<thread>

void performOperation(std::function<void(CarContainer&)> operation, CarContainer& data) {
    operation(data);
}

int main(){
    CarContainer data;
    CreateObejects(data);

    // Displaying all cars
    std::thread displayThread(
        [&](CarContainer& data){
            for (const auto& car : data) {
                std::cout << *car << "\n";
            }
        },
        std::ref(data)
    );
    // std::cout << "All Cars:\n";
    // for (const auto& car : data) {
    //     std::cout << *car << "\n";
    // }

    // Creating a partial function with price parameter fixed to 12000
    auto partialCountCarsFunction = std::bind(CountCarsMatchingCondition, std::placeholders::_1, 12000);
    std::thread partialCountCarsFunctionThread(
        performOperation,
        partialCountCarsFunction,
        std::ref(data)
    );

    // Calculate average horsepower
    std::thread averageHorsePowerThread(
        performOperation,
        AverageHorsePower,
        std::ref(data)
    );

    // Calculate combined insurance cost
    std::thread combinedInsuranceCostThread(
        performOperation,
        CombinedInsuranceCost,
        std::ref(data)
    );

    // Get unique manufacturers with horsepower > 150 and resale value > 25000
    std::thread uniqueManufacturersWithConditionThread(
        performOperation,
        UniqueManufacturersWithCondition,
        std::ref(data)
    );

    displayThread.join();
    partialCountCarsFunctionThread.join();
    averageHorsePowerThread.join();
    combinedInsuranceCostThread.join();
    uniqueManufacturersWithConditionThread.join();

    return 0;
}