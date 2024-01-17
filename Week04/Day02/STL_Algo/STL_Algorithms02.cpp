#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
#include<list>
#include<memory>
#include"Employee.h"

using EmployeePointer = std::shared_ptr<Employee>;
using Container = std::vector<EmployeePointer>;

template <typename T>
void CreateData(T& container) {
    container.emplace_back(
        std::make_shared<Employee>(101, 89000.0f)
    );

    container.emplace_back(
        std::make_shared<Employee>(102, 189000.0f)
    );

    container.emplace_back(
        std::make_shared<Employee>(103, 129000.0f)
    );
}


template <typename T>
void Display(T& values){
    for(auto& val : values) {
        std::cout << val <<"\n";
    }
}

//template specialization
template <>
void Display(Container& values){
    for(auto& val : values) {
        std::cout << *val <<"\n";
    }
}

int main() {
    //Example 01: std::any_of 
    //check if any of the values in the vector is divisible by 5
    std::vector<int> data {10, 17, 19, 21, 20};
    std::cout<<"Check If Any of Element Divisible by 5: ";
    std::cout<<std::boolalpha<< std::any_of(
        data.begin(),
        data.end(),
        [](int number) { return number % 5 == 0; }
    )<<std::endl;



    //Example 02: Any of used with smart pointers in a container
    Container emp_data;
    CreateData(emp_data);

    std::cout<<"Check If Any of Object Has Tax More Than 6000: ";
    std::cout<<std::boolalpha<<std::any_of(
        emp_data.begin(),
        emp_data.end(),
        //check if any employee calculates tax amount which is above 6000
        [](const EmployeePointer& ptr) { return ptr->CalculateTax() > 6000.0f; }
    )<<std::endl;



    //Example 03: check if ALL OF the data values in the container are divisible by 5
    std::cout<<"Check If All of Element Divisible by 5: ";
    std::cout<<std::boolalpha<<std::all_of(
        data.begin(),
        data.end(),
        [](int number) { return number % 5 == 0; }
    )<<std::endl;



    //Example 04: Check if NONE OF the data values are divisible by 5
    std::cout<<"Check If None of Element Divisible by 5: ";
    std::cout<<std::boolalpha<<std::none_of(
        data.begin(),
        data.end(),
        [](int number) { return number % 5 == 0; }
    )<<std::endl;
}