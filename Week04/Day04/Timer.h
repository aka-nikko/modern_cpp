#include <iostream>
#include <chrono>

class Timer {
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by the function: " << duration.count() << " microseconds" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start;
};

// // Your function to measure
// void myFunction() {
//     // Some code you want to measure
// }

// int main() {
//     {
//         Timer timer; // Timer starts when created
//         myFunction(); // Your function to measure
//     } // Timer stops when it goes out of scope, and the destructor prints the duration

//     return 0;
// }
