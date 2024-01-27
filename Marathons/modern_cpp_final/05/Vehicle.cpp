#include"Vehicle.h"

Vehicle::Vehicle(int id, float price, OwnerRef owner, VType permit):
    _id(id), _price(price), _owner(owner), _permit(std::move(permit)) {}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _owner: " << *(rhs._owner.get());
       std::visit([&](auto&& instance) {
        os << *instance;
    }, rhs._permit);
    return os;
}
