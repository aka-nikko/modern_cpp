#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include<vector>
#include<memory>
#include<set>

using CarPointer=std::shared_ptr<Car>;
using CarContainer=std::vector<CarPointer>;

void CreateObejects(CarContainer& data);

void CountCarsMatchingCondition(CarContainer& data, float price);

void AverageHorsePower(CarContainer& data);

void CombinedInsuranceCost(CarContainer& data);

void UniqueManufacturersWithCondition(CarContainer& data);

#endif // FUNCTIONALITIES_H
