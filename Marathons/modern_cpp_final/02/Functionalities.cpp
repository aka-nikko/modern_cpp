#include"Functionalities.h"

void performOperation(std::function<void(Container&)> operation, Container& data) {
    operation(data);
}

void OddNumbers(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Odd Numbers Are: ";
    std::for_each(data.begin(), data.end(), [](int number){
        if(number%2!=0){
            std::cout<<number<<" ";
        }
    });

    std::cout << std::endl;


}

void DivisibleBy4(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Numbers Divisible By 4: ";
    std::for_each(data.begin(), data.end(), [](int number) {
        if (number % 4 == 0) {
            std::cout << number << " ";
        }
    });

    std::cout << std::endl;
}

void SumOfTwoLargestNumbers(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    if (data.size() < 2) {
        throw std::runtime_error("Insufficient elements in the container.");
    }

    Container sortedData = data;
    std::sort(sortedData.begin(), sortedData.end(), std::greater<int>());

    int largest = sortedData[0];
    int secondLargest = std::max(sortedData[1], sortedData[2]);

    std::cout << "Sum of two largest numbers: " << largest + secondLargest << std::endl;

}

void MinimumElement(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    auto minElementIterator = std::min_element(data.begin(), data.end());
    int position = std::distance(data.begin(), minElementIterator);
    std::cout << "Minimum element: " << *minElementIterator << " at position: " << position << std::endl;
}