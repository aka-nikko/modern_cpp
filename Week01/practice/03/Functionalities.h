#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include"Car.h"
#include<vector>

using VehiclePointer = std::shared_ptr<Vehicle>;
using VehicleContainer = std::vector<VehiclePointer>;
using CarPointer = std::shared_ptr<Car>;
using CarContainer = std::vector<CarPointer>;

void CreateObjects(VehicleContainer& data, Insurance& ins1, Insurance& ins2);

void DisplayObjects(VehicleContainer& data);

CarContainer InsuranceOverThreshold(VehicleContainer& data, float amount);

std::vector<float> CarPricesOfVehicleType(VehicleContainer& data, VehicleType type);

std::vector<std::string> CarColorOfPrivateVehicle(VehicleContainer& data);

float AverageInsuranceAmount(VehicleContainer& data);

#endif // FUNCTIONALITIES_H
