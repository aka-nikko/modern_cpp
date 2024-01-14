#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<memory>
#include<vector>
#include"Customer.h"

using Pointer  = std::shared_ptr<Customer>;
using Container= std::vector<Pointer>;

/*
    Function to create Objects
*/
void CreateObjects(Container& data);

void DisplayObjects(const Container& data);

#endif // FUNCTIONALITIES_H
