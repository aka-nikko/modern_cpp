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
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
}

//template specialization
template <>
void Display(Container& values){
    for(auto& val : values) {
        std::cout << *val <<"\n";
    }
}

int main() {
    //Example 01: Copy all elements from one container to another
    std::vector<int> data {1,2,3,4,5};

    //Copy data into a new container called results
    std::vector<int> result(data.size()); //to have a size so that memory is allocated

    std::copy(
        data.begin(), //source starting
        data.end(), //last position
        result.begin() //starting point for destination
    );    
    std::cout<<"Copy: "<<std::endl;
    Display<std::vector<int>>(result);



    //Example 02 : Copy elements from one container to another if they satisfy a condition
    //Step 1 : Actual copy based on condition
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),
        [](int number) { return number > 3;  }
    );

    //Step 2: determine new size of result
    int new_size = std::distance(result.begin(), itr);

    //Step 3: resize the result according to number of elements occupied
    result.resize(new_size);
    std::cout<<"Copy If Condition True: "<<std::endl;
    Display<std::vector<int>>(result);



    //Example 03: Copy if using smart pointer objects
    Container emp_data;
    CreateData(emp_data);

    Container emp_result(emp_data.size());

    auto itr1 = std::copy_if(
        emp_data.begin(),
        emp_data.end(),
        emp_result.begin(),
        [](const EmployeePointer& element) { return element->CalculateTax() > 10000.0f ; }
    );

    //step 2: determine new size of result
    int new_size1 = std::distance(emp_result.begin(), itr1);

    //step 3: resize the result according to number of elements occupied
    emp_result.resize( new_size1  );

    std::cout<<"Copy If Condition True (Smart Pointer): "<<std::endl;
    Display(emp_result);



    //Example 04: Accumulate with binary operation +
    int ans = std::accumulate(
        data.begin(),
        data.end(),
        0
    );

    std::cout<<"Sum: "<<ans<<"\n";

    //multiply (product)
    int ans1 = std::accumulate(
        data.begin(),
        data.end(),
        1,
        [](int current_ans, int number) {  return current_ans * number; }
    );
}
