#include "Functionalities.h"
#include <algorithm>

std::function<void(const Matrix& matrix)> displayRowSums = [](const Matrix& matrix) {
    for (const auto& row : matrix) {
        int sum = 0;
        for (int num : row) {
            sum += num;
        }
        std::cout << sum << std::endl;
    }
};

std::function<void(const Matrix& matrix)> displayHighestValue = [](const Matrix& matrix) {
    int highestValue = matrix[0][0];
    for (const auto& row : matrix) {
        for (int num : row) {
            highestValue = std::max(highestValue, num);
        }
    }
    std::cout << highestValue << std::endl;
};

std::function<void(const Matrix& matrix)> displaySquareOfLast = [](const Matrix& matrix) {
    int lastValue = matrix.back().back();
    std::cout << lastValue * lastValue << std::endl;
};

std::function<void(const Matrix& matrix)> displayMaxInColumns = [](const Matrix& matrix) {
    for (size_t col = 0; col < matrix[0].size(); ++col) {
        int maxInColumn = matrix[0][col];
        for (size_t row = 1; row < matrix.size(); ++row) {
            maxInColumn = std::max(maxInColumn, matrix[row][col]);
        }
        std::cout << maxInColumn << std::endl;
    }
};

