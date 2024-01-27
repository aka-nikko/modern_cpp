#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<unordered_map>
#include<algorithm>
#include<memory>
#include<variant>
#include<numeric>
#include<optional>
#include<future>
#include"Developer.h"
#include"CodeTester.h"

using DeveloperPointer=std::shared_ptr<Developer>;
using TesterPointer=std::shared_ptr<CodeTester>;
using Vtype=std::variant<DeveloperPointer,TesterPointer>;
using Container=std::unordered_map<std::string, Vtype>;


//Function to Create Objects
void CreateObjects(Container& data);

//Function to find employees with experience below 6
Container FindEmployeesWithExperienceBelowSix(const Container& data);

//Function to calculate average salary of CodeTesters
float CalculateAverageSalaryOfCodeTesters(const Container& data);

//Function to count employees with salary above 50000
int CountEmployeesWithSalaryAbove50K(const Container& data);

//Function to find and display the salary of an employee by _id
std::optional<float> FindSalaryById(const Container& data, const std::string& employeeId);

//Function to check if all employees have salary above 60000
bool AllSalariesAbove60000(const Container& data);

#endif // FUNCTIONALITIES_H

