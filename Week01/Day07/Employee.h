#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee{
private:
    int _id;
public:
    Employee(int id):_id(id){};
    ~Employee()=default;

    int id() const { return _id; }
    void setId(int id) { _id = id; }
};

#endif // EMPLOYEE_H
