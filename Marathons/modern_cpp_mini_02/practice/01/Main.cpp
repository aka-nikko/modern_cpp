#include"Functionalities.h"

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    Matrix matrix(rows, std::vector<int>(cols));

    std::cout << "Enter the matrix values:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Sum of values in each row:" << std::endl;
    displayRowSums(matrix);

    std::cout << "Highest value in the matrix:" << std::endl;
    displayHighestValue(matrix);

    std::cout << "Square of the number at the last position:" << std::endl;
    displaySquareOfLast(matrix);

    std::cout << "Maximum number in each column:" << std::endl;
    displayMaxInColumns(matrix);
}
