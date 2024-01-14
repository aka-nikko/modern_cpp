#include<iostream>
#include<list>
#include<vector>
#include<memory>
#include"Employee.h"


int main(){
    //Scenario 01
    std::list<Employee> data1;
    Employee e1(101);    //Object in main
    data1.push_back(e1); //Take a reference of e1 & store in data list
                         //Create Copy of e1 & Store in List

    //Scenario 02
    std::list<Employee> data2;
    data2.push_back(Employee(101)); //Creates a temp objects and
                                    //copies it to list

    //Scenario 03
    std::list<Employee> data2;
    data2.emplace_back(Employee(101));  //Directly places the object in list

    return 0;
}


/*
    Scenario 01:
    Make lvalue data object. Allocate a new node in the list.
    Copy data into the list (UNOPTIMIZED)

    Scenario 02:
    Male a temporary object. Allocate a new node in the list.
    Move the temporary data into the new node allocated.
*/