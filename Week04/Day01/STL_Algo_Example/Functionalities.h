#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<functional>
#include<memory>
#include<vector>
#include"Employee.h"

/*
    Identifier AverageSalary is a varaible name (name of object)

    If a variable is declared in a file but has to be initialied
    in a seperate file, such variables must be marked as "extern"
*/
using Pointer=std::shared_ptr<Employee>;
using Container=std::vector<Pointer>;

extern std::function<float(Container&)> AverageSalary;

//Function returns salary of employye whose id is given as second parameter
extern std::function<float(Container&, int)> SalaryGivenId;

#endif // FUNCTIONALITIES_H
