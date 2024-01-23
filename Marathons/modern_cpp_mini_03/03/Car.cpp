#include"Car.h"

Car::Car(int seat_count, float price, CarChassis chasis):
    _seat_count(seat_count), _price(price), _chasis(chasis) {}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_seat_count: " << rhs._seat_count
       << " _price: " << rhs._price
       << " _chasis: " << static_cast<int>(rhs._chasis);
    return os;
}

