#include<iostream>
#include<memory>
#include"Vehicle.h"
#include"VehicleType.h"

int main(){
    std::shared_ptr<Vehicle> ptr = std::make_shared<Vehicle>(
        101,
        "City",
        100000.0f,
        VehicleType::PERSONAL
    );
    return 0;
}