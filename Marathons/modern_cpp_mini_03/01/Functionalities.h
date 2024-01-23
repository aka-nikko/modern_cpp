#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <array>
#include <vector>
#include <future>
#include <mutex>
#include <thread>
#include <condition_variable>

extern std::mutex mt;
extern std::mutex mt_new;
extern std::condition_variable cv;
extern bool flag;

//Function to Genrate 5 integers
std::array<int, 5> Generate5Integers(std::future<int>& ft, std::array<int, 5>& arr);

//Function to sttore squares of each number
void StoreSquareInResult(const std::array<int, 5>& arr, std::vector<int>& result);

//Function to print sum of numbers
void PrintSumOfAllNumbers(const std::array<int, 5>& arr);

//Function to store cubes of each number
void StoreCubeOfNumbersInResult(const std::array<int, 5>& arr, std::vector<int>& cubes);

//Function to display the result container
void DisplayResult(const std::vector<int>& result);

#endif // FUNCTIONALITIES_H
