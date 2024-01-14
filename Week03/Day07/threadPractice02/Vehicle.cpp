#include"Vehicle.h"

Vehicle::Vehicle(std::string id, std::string manufacturer, float price):
    _id(id), _manufacturer(manufacturer), _price(price) {}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _manufacturer: " << rhs._manufacturer
       << " _price: " << rhs._price;
    return os;
}
