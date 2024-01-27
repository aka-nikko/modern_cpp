#include"Owner.h"

Owner::Owner(std::string name, std::string city, OwnerType type):
    _name(name), _city(city), _type(type) {}

std::ostream &operator<<(std::ostream &os, const Owner &rhs) {
    os << "_name: " << rhs._name
       << " _city: " << rhs._city
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}
