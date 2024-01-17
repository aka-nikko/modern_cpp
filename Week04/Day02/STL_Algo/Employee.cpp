#include "Employee.h"

Employee::Employee(int id, float salary)
    : _id(id), _salary(salary){}

float Employee::CalculateTax(){
    return 0.1f * _salary;
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _salary: " << rhs._salary;
    return os;
}
