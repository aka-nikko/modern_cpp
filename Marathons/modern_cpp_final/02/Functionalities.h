#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using Container=std::vector<int>;

//Function to Perform Operations
void performOperation(std::function<void(Container&)> operation, Container& data);

//Function to Print Odd Numbers from Container
void OddNumbers(const Container& data);

//Function to Print Numbers Divisible by 4
void DivisibleBy4(const Container& data);

//Function to Print Sum of Largest and Second Largest Numbers
void SumOfTwoLargestNumbers(const Container& data);

//Function to Print Minimum Element
void MinimumElement(const Container& data);

#endif // FUNCTIONALITIES_H
