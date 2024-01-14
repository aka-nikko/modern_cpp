#include "Car.h"

Car::Car(std::string id, std::string brand, CarType type, std::shared_ptr<Engine> engine, float price):
    carID(id), carBrand(brand), carType(type), carEngine(engine), carPrice(price){}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    std::string type;
    switch (static_cast<int>(rhs.carType)){
    case 0:
        type="SEDAN";
        break;
    case 1:
        type="SUV";
        break;
    case 2:
        type="SPORTS";
        break;
    case 3:
        type="HATCHBACK";
        break;
    }
    os << "carID: " << rhs.carID
       << " carBrand: " << rhs.carBrand
       << " carType: " << type
       << "\ncarEngine: " << *rhs.carEngine
       << " carPrice: " << rhs.carPrice;
    return os;
}
