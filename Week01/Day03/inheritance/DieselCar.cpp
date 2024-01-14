#include"DieselCar.h"

DieselCar::DieselCar(int id, std::string name, float price, VehicleType type, int capacity):
    Vehicle(id, name, price, type), _fuel_tank_capacity(capacity){}

DieselCar::DieselCar(int id, std::string name, VehicleType type, int capacity):
    Vehicle(id, name, type), _fuel_tank_capacity(capacity){}

void DieselCar::CalculateRegistrationCharge(){
    std::cout<<"Tax on Diesel Car is 15%: "<<0.15f*price()<<"\n";
}

std::ostream &operator<<(std::ostream &os, const DieselCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity;
    return os;
}

void DieselCar::display(){
    Vehicle::display();
    std::cout   << " _fuel_tank_capacity: " << _fuel_tank_capacity << std::endl;
}