#include"Order.h"

//Parameterized Constructor
Order::Order(std::string id, float value, OrderType type, float discount):
    _id(id), _value(value), _type(type), _discount(discount){}

//Insertions Operator (<<) Overloaded
std::ostream &operator<<(std::ostream &os, const Order &rhs) {
    os << "_id: " << rhs._id
       << " _value: " << rhs._value
       << " _type: " << static_cast<int>(rhs._type)
       << " _discount: " << rhs._discount;
    return os;
}
