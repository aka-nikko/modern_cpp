#include"HybridCar.h"

HybridCar::HybridCar(int id, std::string name, float price, VehicleType type, int capacity, int battery):
    Vehicle(id, name, price, type), _fuel_tank_capacity(capacity), _battery_percentage(battery){}

HybridCar::HybridCar(int id, std::string name, VehicleType type, int capacity, int battery):
    Vehicle(id, name, type), _fuel_tank_capacity(capacity), _battery_percentage(battery){}

void HybridCar::CalculateRegistrationCharge(){
    std::cout<<"Tax on Hybrid Car is 10%: "<<0.10f*price()<<"\n";
}
    
std::ostream &operator<<(std::ostream &os, const HybridCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity
       << " _battery_percentage: " << rhs._battery_percentage;
    return os;
}

void HybridCar::display(){
    Vehicle::display();
    std::cout   << " _fuel_tank_capacity: " << _fuel_tank_capacity
                << " _battery_percentage: " << _battery_percentage << std::endl;
}
