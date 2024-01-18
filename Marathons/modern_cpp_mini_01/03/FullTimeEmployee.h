#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include<iostream>
#include"Employee.h"
#include"Grade.h"

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
                     std::shared_ptr<Department> department, 
                     std::string project_name, std::string employee_location, 
                     Grade grade, int bonus_percent);

    //Copy Constructor
    FullTimeEmployee(const FullTimeEmployee&)=delete;

    //Copy Assignment Operator
    FullTimeEmployee& operator=(const FullTimeEmployee&)=delete;

    //Move Constructor
    FullTimeEmployee(const FullTimeEmployee&&)=delete;

    //Move Assignment Operator
    FullTimeEmployee& operator=(const FullTimeEmployee&&)=delete;

    //Default Destructor
    ~FullTimeEmployee()=default;

    //Function to Calculate Bonus
    float CalculateBonus() override;

    //Getter and Setter Functions
    std::string projectName() const { return _project_name; }
    void setProjectName(const std::string &project_name) { _project_name = project_name; }

    std::string employeeLocation() const { return _employee_location; }
    void setEmployeeLocation(const std::string &employee_location) { _employee_location = employee_location; }

    Grade grade() const { return _grade; }
    void setGrade(const Grade &grade) { _grade = grade; }

    int bonusPercent() const { return _bonus_percent; }
    void setBonusPercent(int bonus_percent) { _bonus_percent = bonus_percent; }

    friend std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs);
};


#endif // FULLTIMEEMPLOYEE_H
