#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Employee.h"
#include"BusinessOwner.h"
#include<iostream>
#include<variant>
#include<memory>
#include<vector>

//I need alias for shared pointer to Employee
using EmpPointer=std::shared_ptr<Employee>;

//I need alias for shared pointer to BusinessOwner
using BusinessPointer=std::shared_ptr<BusinessOwner>;

//I need alias for variants of above 2 pointers.
using VType=std::variant<EmpPointer, BusinessPointer>;

//I finally want a container of above variants.
using Container=std::vector<VType>;

void CreateObjects(Container& data){
    data.emplace_back(
        std::make_shared<Employee>()
    );

    data.emplace_back(
        std::make_shared<BusinessOwner>()
    );
}

#endif // FUNCTIONALITIES_H
