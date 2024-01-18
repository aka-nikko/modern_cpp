#include"Department.h"

Department::Department(std::string id, int size):
    _id(id), _size(size){}

std::ostream &operator<<(std::ostream &os, const Department &rhs) {
    os << "_id: " << rhs._id
       << " _size: " << rhs._size;
    return os;
}

