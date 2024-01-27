#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee{
    private:
        std::string _name;
        std::string _id;
        float _salary;

    public:
        //Default Constructor
        Employee()=default;

        //Parameterized Constructor
        Employee(std::string name, std::string id, float salary);

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

        //Pure Virtual Function
        virtual float CalculateBonus()=0;

        //Getter Functions
        std::string name() const { return _name; }
        std::string id() const { return _id; }
        float salary() const { return _salary; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
