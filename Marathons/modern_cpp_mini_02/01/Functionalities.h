#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<functional>
#include<vector>

/*
    Lamda Function that takes string from user and
    returns non vovel characters from the string
*/
extern std::function<std::string(std::string&)> findNonVowels;

/*
    Lamda Function that takes list of numbers from user and
    returns sum of all odd numbers from list
*/
extern std::function<int(std::vector<int>&)> sumOfOddNumbers;

/*
    Lamda Function that takes list of numbers from user and
    returns average of all even numbers from the list
*/
extern std::function<float(std::vector<int>&)> averageOfEvenNumbers;

/*
    Lamda Function that takes list of numbers from user and
    returns sum of squares of all even numbers from list
*/
extern std::function<float(std::vector<int>&)> sumOfSquareOfEvenNumbers;

/*
    Lamda Function that takes list of numbers from user and
    returns list of odd numbers divisible by 7
*/
extern std::function<std::vector<int>(int)> numbersDivisibleBySeven;

#endif // FUNCTIONALITIES_H
