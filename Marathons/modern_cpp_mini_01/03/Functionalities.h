#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"FullTimeEmployee.h"
#include<memory>
#include<list>

using Pointer = std::shared_ptr<FullTimeEmployee>;
using Container = std::list<Pointer>;

//Function To Create Objects
void CreateObjects(Container& data);

//Function To Display Objects
void DisplayObjects(Container& data);

//Function to Display Bonus of Each Employee
void InvokeCalculateBonus(Container& data);

//Function to Display Employee with Lowest Salary
void LowestSalaryEmployee(Container& data);

//Function to Display Locations of Given Grade Employees
void EmployeeLocationFromGrade(Container& data, Grade grade);

//Function to Return Project Name of Given Employee
std::string ProjectNameFromID(Container& data, std::string id);

#endif // FUNCTIONALITIES_H
