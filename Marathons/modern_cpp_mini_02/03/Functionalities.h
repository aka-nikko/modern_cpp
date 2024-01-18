#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include"EvTruck.h"
#include<memory>
#include<vector>

using Pointer  = std::shared_ptr<Vehicle>;
using Container= std::vector<Pointer>;

using EnginePointer = std::shared_ptr<Engine>;
using EngineContainer = std::vector<EnginePointer>;

//Function to Create Car Objects
void CreateCarObjects(Container& data, EngineContainer& engineData);

//Function to Create EvTruck Objects
void CreateEvTruckObjects(Container& data);

//Function to Display Objects
void DisplayObjects(Container& data);

//Function to Search Vehicle By ID
std::shared_ptr<Vehicle> SearchVehicleById(Container& data, std::string id);

//Function to Get Count of Given Vehicle
int CountOfGivenVehicle(Container& data, std::string searchVehicle);

//Function to Get Average Price of Given Vehicles
float AveragePriceOfGivenVehicle(Container& data, std::string searchVehicle);

//Function to Calculate RegistrationCharge
Container RegistrationChargeCondition(Container& data);

#endif // FUNCTIONALITIES_H
