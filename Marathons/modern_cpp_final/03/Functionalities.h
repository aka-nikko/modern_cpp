#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"FullTimeEmployee.h"
#include<list>
#include<memory>
#include<algorithm>
#include<future>

using Pointer=std::shared_ptr<FullTimeEmployee>;
using Container=std::list<Pointer>;

//Function To Create Objects
void CreateObjects(Container& data);

//Function to Display Bonus of Each Employee
void InvokeCalculateBonus(Container& data);

//Function to Display Employee Details with Maximum Salary
void DisplayEmployeeWithMaxSalary(const Container& data);

//Function to Display All Employee Locations of Given Grade
void AllEmployeeLocationsOfGivenGrade(const Container& data, std::future<Grade>& ft);

//Function to Return Project name of Given Employee ID
std::string ProjectNameOfGivenID(const Container& data, std::future<std::string>& ft);

#endif // FUNCTIONALITIES_H

