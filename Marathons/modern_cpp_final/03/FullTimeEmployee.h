#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include<iostream>
#include"Grade.h"
#include"Employee.h"

class FullTimeEmployee: public Employee{
    private:
        std::string _project_name;
        std::string _employee_location;
        Grade _grade;
        int _bonus_percent;

    public:
        //Default Constructor
        FullTimeEmployee()=delete;

        //Parameterized Constructor
        FullTimeEmployee(std::string name, std::string id, float salary, 
                        std::string project_name, std::string employee_location, 
                        Grade grade, int bonus_percent);

        //Copy Constructor
        FullTimeEmployee(const FullTimeEmployee&)=delete;

        //Copy Assignment Operator
        FullTimeEmployee& operator=(const FullTimeEmployee&)=delete;

        //Move Constructor
        FullTimeEmployee(FullTimeEmployee&&)=delete;

        //Move Assignment Operator
        FullTimeEmployee& operator=(FullTimeEmployee&&)=delete;

        //Destructor
        ~FullTimeEmployee()=default;

        //Virtual Function
        float CalculateBonus();

        //Getter Functions
        std::string projectName() const { return _project_name; }
        std::string employeeLocation() const { return _employee_location; }
        Grade grade() const { return _grade; }
        int bonusPercent() const { return _bonus_percent; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs);
};

#endif // FULLTIMEEMPLOYEE_H
