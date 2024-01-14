#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"EmployeeType.h"

class Employee{
    private:
        std::string _name;
        EmployeeType _type;
        float _salary;

    public:
        //Default Constructor
        Employee()=delete;

        //Parameterized Constructor
        Employee(std::string name, EmployeeType type, float salary);

        //Copy Constructor
        Employee(const Employee&)=delete;

        //Copy Assignment Operator
        Employee& operator=(const Employee&)=delete;

        //Move Constructor
        Employee(Employee&&)=delete;

        //Move Assignment Operator
        Employee& operator=(Employee&&)=delete;

        //Destructor
        ~Employee()=default;

        //Getter Functions
        std::string name() const { return _name; }
        EmployeeType type() const { return _type; }
        float salary() const { return _salary; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
