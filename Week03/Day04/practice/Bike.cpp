#include"Bike.h"

Bike::Bike(std::string id, float price, VehicleType type):
    _id(id), _price(price), _type(type){}

Bike::Bike(std::string id, float price):
    _id(id), _price(price){}

std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}
