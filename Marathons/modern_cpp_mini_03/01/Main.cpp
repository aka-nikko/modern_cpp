#include "Functionalities.h"

int main() {
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::array<int, 5> arr;
    std::future<std::array<int, 5>> result_ft = std::async(std::launch::async, &Generate5Integers, std::ref(ft), std::ref(arr));

    int val = 0;
    std::cout<<"Enter a Number: "<<std::endl;
    std::cin >> val;
    pr.set_value(val);

    std::vector<int> result;
    std::vector<int> cubes;

    std::thread t1(&StoreSquareInResult, std::cref(arr), std::ref(result));
    std::thread t2(&PrintSumOfAllNumbers, std::cref(arr));
    std::thread t3(&StoreCubeOfNumbersInResult, std::cref(arr), std::ref(cubes));
    std::thread t4(&DisplayResult, std::cref(result));

    t1.join();
    t2.join();
    t3.join();

    flag = true;
    cv.notify_one();

    t4.join();

    return 0;
}
