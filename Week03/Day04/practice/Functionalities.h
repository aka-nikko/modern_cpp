#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Car.h"
#include"Bike.h"
#include<list>
#include<memory>
#include<variant>
#include<optional>

using CarPointer = std::shared_ptr<Car>;

using BikePointer = std::shared_ptr<Bike>;

using VType=std::variant<CarPointer, BikePointer>;

using Container=std::list<VType>;

/*
    Taking empty container by lvalye reference and fill it with variant objects
    It should return void
*/
void CreateObjects(Container& data);

/*
    Average price can be fount using visit and total
*/
float AveragePrice(const Container & data);

/*
    Find instance with minimum price (all vehicles have prices which are unique)
*/
VType MinimumPriceInstance(const Container& data);

/*
    Check if given ID is present in any of the instance
*/
bool IfIdExist(const Container& data, std::string id);

/*
    Return all instances whose type matches with type passed
*/
std::optional<std::list<VType>> InstanceMatchingType(const Container& data, VehicleType type);

#endif // FUNCTIONALITIES_H
