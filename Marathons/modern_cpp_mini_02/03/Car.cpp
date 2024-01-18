#include"Car.h"

Car::Car(std::string id, std::string manufacturer, float price, 
        CarCategory carCategory, EngineRef engine):
    Vehicle(id, manufacturer, price), _carCategory(carCategory), _engine(engine) {}

float Car::CalculateRegistrationCharges(){
    return 0.1*price();
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _carCategory: " << static_cast<int>(rhs._carCategory)
       << " _engine: " << *(rhs._engine.get());
    return os;
}