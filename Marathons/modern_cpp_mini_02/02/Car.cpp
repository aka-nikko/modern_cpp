#include"Car.h"

Car::Car(std::string manufacturer, std::string model, int saleUnit, 
        float resaleValue, float price, int horsePower):
    _manufacturer(manufacturer), _model(model), _saleUnit(saleUnit), 
    _resaleValue(resaleValue), _price(price), _horsePower(horsePower){}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_manufacturer: " << rhs._manufacturer
       << " _model: " << rhs._model
       << " _saleUnit: " << rhs._saleUnit
       << " _resaleValue: " << rhs._resaleValue
       << " _price: " << rhs._price
       << " _horsePower: " << rhs._horsePower;
    return os;
}
