#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<memory>
#include"Department.h"

class Employee{
private:
    std::string _name;
    std::string _id;
    float _salary;
    std::shared_ptr<Department> _department;

public:
    //Default Constructor
    Employee()=default;

    //Parameterized Constructor
    Employee(std::string name, std::string id, float salary, std::shared_ptr<Department> department);

    //Copy Constructor
    Employee(const Employee&)=delete;

    //Copy Assignment Operator
    Employee& operator=(const Employee&)=delete;

    //Move Constructor
    Employee(const Employee&&)=delete;

    //Move Assignment Operator
    Employee& operator=(const Employee&&)=delete;

    //Default Destructor
    ~Employee()=default;

    //Pure Virtual Function
    virtual float CalculateBonus()=0;

    //Getter and Setter Functions
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    std::shared_ptr<Department> department() const { return _department; }
    void setDepartment(const std::shared_ptr<Department> &department) { _department = department; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
