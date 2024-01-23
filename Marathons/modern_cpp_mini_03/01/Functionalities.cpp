#include "Functionalities.h"

//Mutex lock condition variable
std::mutex mt;
std::mutex mt_new;
std::condition_variable cv;
bool flag = false;

std::array<int, 5> Generate5Integers(std::future<int>& ft, std::array<int, 5>& arr) {
    int number = ft.get();
    int count = 0;
    while (count < 5) {
        arr[count] = number;
        count++;
        number++;
    }

    return arr;
}

void StoreSquareInResult(const std::array<int, 5>& arr, std::vector<int>& result) {
    if (arr.empty()) {
        throw std::runtime_error("Array is Empty!");
    }

    for (const int& val : arr) {
        result.emplace_back(val * val);
    }
}

void PrintSumOfAllNumbers(const std::array<int, 5>& arr) {
    if (arr.empty()) {
        throw std::runtime_error("Result is Empty!");
    }

    float sum = 0.0f;
    for (const int& val : arr) {
        sum = sum + val;
    }

    std::lock_guard<std::mutex> lk(mt);
    std::cout << "Sum Of Numbers: " << sum << std::endl;
}

void StoreCubeOfNumbersInResult(const std::array<int, 5>& arr, std::vector<int>& cubes) {
    if (arr.empty()) {
        throw std::runtime_error("Data is Empty!");
    }

    for (const int& val : arr) {
        cubes.emplace_back(val * val * val);
    }

    std::lock_guard<std::mutex> lk(mt);
    std::cout << "Cubes Of Numbers: " << std::endl;
    for (const int& val : cubes) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void DisplayResult(const std::vector<int>& result) {
    std::unique_lock<std::mutex> ul(mt_new);
    cv.wait(ul, []() { return flag; });

    {
        std::lock_guard<std::mutex> lk(mt);
        if (result.empty()) {
            throw std::runtime_error("Data is Empty!");
        }

        std::cout << "Elements of Result Vector:" << std::endl;
        for (const int& val : result) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
