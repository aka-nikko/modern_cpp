#include"EvCar.h"

EvCar::EvCar(int id, std::string name, float price, VehicleType type, int battery):
    Vehicle(id, name, price, type), _battery_percentage(battery){}

EvCar::EvCar(int id, std::string name, VehicleType type, int battery):
    Vehicle(id, name, type), _battery_percentage(battery){}

void EvCar::CalculateRegistrationCharge(){
    std::cout<<"Tax on Electric Car is 1%: "<<0.01f*price()<<"\n";
}
    
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _battery_percentage: " << rhs._battery_percentage;
    return os;
}

void EvCar::display(){
    Vehicle::display();
    std::cout<< " _battery_percentage: " << _battery_percentage << std::endl;
}