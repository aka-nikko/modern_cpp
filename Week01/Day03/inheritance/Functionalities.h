#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<memory>
#include<vector>
#include"Vehicle.h"

//Step 01: Create an alias "Pointer" which is an alternate name
//for std::shared_ptr to Vehicle
using Pointer  = std::shared_ptr<Vehicle>;

//Step 02: Now Specify alternate Container which indicates
// a standard vector of "Pointer" where Pointer is explained above.
using Container= std::vector<Pointer>;


void CreateObjects(Container& data);

void DisplayObjects(const Container& data);

float AveragePrice(Container& data);

#endif // FUNCTIONALITIES_H
