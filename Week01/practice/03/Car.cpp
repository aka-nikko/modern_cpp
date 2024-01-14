#include"Car.h"

Car::Car(std::string id, int registration, VehicleType vtype, Insurance& insuranceplan, CarType ctype, float price, std::string color):
    Vehicle(id, registration, vtype, insuranceplan), carType(ctype), carPrice(price), carColor(color){}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " carType: " << static_cast<int>(rhs.carType)
       << " carPrice: " << rhs.carPrice
       << " carColor: " << rhs.carColor;
    return os;
}



