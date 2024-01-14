#include"Car.h"

Car::Car(int id, std::string model, float price, RefType engine):
    _id(id), _model(model), _price(price), _engine(engine) {}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _price: " << rhs._price
       << " _engine: " << *(rhs._engine.get());
    return os;
}

