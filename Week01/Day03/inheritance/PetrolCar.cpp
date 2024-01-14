#include"PetrolCar.h"

PetrolCar::PetrolCar(int id, std::string name, float price, VehicleType type, int capacity):
    Vehicle(id, name, price, type), _fuel_tank_capacity(capacity){}

PetrolCar::PetrolCar(int id, std::string name, VehicleType type, int capacity):
    Vehicle(id, name, type), _fuel_tank_capacity(capacity){}

void PetrolCar::CalculateRegistrationCharge(){
    std::cout<<"Tax on Petrol Car is 13%: "<<0.13f*price()<<"\n";
}

std::ostream &operator<<(std::ostream &os, const PetrolCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity;
    return os;
}

void PetrolCar::display(){
    Vehicle::display();
    std::cout<<" _fuel_tank_capacity: " << _fuel_tank_capacity << std::endl;
}