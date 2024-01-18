#include <iostream>
#include <vector>
#include<functional>

using Matrix = std::vector<std::vector<int>>;

// Function to display the sum of values in each row of the matrix
extern std::function<void(const Matrix& matrix)> displayRowSums;

// Function to display the highest value in the matrix
extern std::function<void(const Matrix& matrix)> displayHighestValue;

// Function to display the square of the number at the last position of the matrix
extern std::function<void(const Matrix& matrix)> displaySquareOfLast;

// Function to display the maximum number in each column of the matrix
extern std::function<void(const Matrix& matrix)> displayMaxInColumns;
