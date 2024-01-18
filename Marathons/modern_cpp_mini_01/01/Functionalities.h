#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<memory>
#include<list>
#include"Order.h"

using Pointer = std::shared_ptr<Order>;
using Container = std::list<Pointer>;

//Function to Create Objects
void CreateObjects(Container& data);

//Function to Display Objects
void DisplayObjects(Container& data);

//Function to Return Order ID with Highest Discount
std::string HighestDiscountID(Container& data);

//Function to Return OrderType from Provided ID
OrderType OrderTypeFromID(Container& data, std::string id);

//Function to Return Average of all Order Values
float AverageOfValues(Container& data);

//Function to Return N Instances.
Container FirstNInstances(Container& data, int N);

#endif // FUNCTIONALITIES_H
