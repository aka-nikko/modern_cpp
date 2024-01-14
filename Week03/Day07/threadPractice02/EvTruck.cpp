#include"EvTruck.h"

EvTruck::EvTruck(std::string id, std::string manufacturer, float price, 
                int batteryCapacity):
    Vehicle(id, manufacturer, price), _batteryCapacity(batteryCapacity){}

float EvTruck::CalculateRegistrationCharges(){
    return 0.0f;
}

std::ostream &operator<<(std::ostream &os, const EvTruck &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    return os;
}
