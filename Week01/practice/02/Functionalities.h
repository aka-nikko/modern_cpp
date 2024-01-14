#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include"Car.h"

using Pointer = std::shared_ptr<Car>;
using Container = std::vector<Pointer>;
using EngineContainer=std::vector<Engine>;

void CreateObjects(Container& data, Engine& eng1, Engine& eng2, Engine& eng3);

int FindHorsePowerByCarID(const Container& data, const std::string id);

Container TorqueAbove80(const Container& data);

EngineContainer CarsOfGivenType(const Container& data, CarType type);

float AverageHorsePower(const Container& data);

std::string LowestPriceCarID(const Container& data);

float CombinedPrice(Pointer& car1, Pointer& car2);

void DisplayObjects(const Container& data);

#endif // FUNCTIONALITIES_H
