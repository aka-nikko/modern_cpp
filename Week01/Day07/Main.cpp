#include<iostream>
#include<list>
#include<vector>
#include<memory>
#include"Employee.h"

using Pointer = std::shared_ptr<Employee>;
using List = std::list<Pointer>;
using Vector = std::vector<Pointer>;

void CreateObjects(List& l1, Vector& v1){
    l1.emplace_back(
        std::make_shared<Employee>(101)
    );
    l1.emplace_back(
        std::make_shared<Employee>(102)
    );
    l1.emplace_back(
        std::make_shared<Employee>(103)
    );
    
    v1.emplace_back(
        std::make_shared<Employee>(201)
    );
    v1.emplace_back(
        std::make_shared<Employee>(202)
    );
    v1.emplace_back(
        std::make_shared<Employee>(203)
    );
    
    
}

int main(){
    List l1;
    Vector v1;
    CreateObjects(l1, v1);
    return 0;
}


/*
    Types of Common Logic Building Exercises
    
    01. Total or Algebraic Sum Operation
        1). Create an initial total variable with initial value 0
        2). For each item to be added to total, do the following-
            a). Fetch the item
            b). Add the item to sum
            c). update the sum
        3). Return the final sum

    02. Find Min Value from a Collection
        eg. Find lowest (min) integer from an array
        1). Create an initial min value WHICH MUST BE EQUAL TO THE FIRST
            ITEM FROM THE COLLECTION
        2). For each item in the collection, do the following-
            a). Fetch the item
            b). compare the item with "MIN_VALUE" so far
                b1). If current item is larger then MIN_VALUE, "ignore"
                b2). If current item is smaller, update MIN_VALUE as "current_item"
        3). Finally, the MIN_VALUE now holds "the global minima"

    03. Find an Attribute associated with the "min" value object
        eg. Finding the car with minimum mileage & return this mileage
        1). Create an initial min value WHICH MUST BE EQUAL TO THE FIRST
            ITEM FROM THE COLLECTION
        2). Also save the attribute (to be returned) of the first item
        3). For each object, do the following-
            a). Compare and check whether current val is lower than min
                a1). If yes, update min, update associated value
                a2). If no, IGNORE
        4). Return Associated Value
*/