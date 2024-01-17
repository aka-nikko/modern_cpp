#include<algorithm>
#include<numeric>
#include<iostream>
#include<vector>
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
    //Example 01: Sort data in ascending order (in-place sort)
    std::vector<int> data {1, 2, 5, 4, 10, 7, 16, 8, 12};
    
    //Sata is now sorted in-place (modifies original input)
    std::sort(data.begin(), data.end()); 

    std::cout<<"Sorted Data: ";
    Display<std::vector<int>>(data);



    //Example 02: Sort data in ascending order
    std::vector<EmployeePointer> emp_data;
    CreateData(emp_data);

    std::sort(  
        emp_data.begin(), 
        emp_data.end(),
        [](const EmployeePointer& emp1, const EmployeePointer& emp2){
            return emp1->salary()  <  emp2->salary();
        }
    );
    std::cout<<"Sorted Objects By Salary: "<<std::endl;
    Display<Container>(emp_data);
    


    //Example 03: Find_if (find the first occurence of the element 
    //satisfying the condition)
    auto itr = std::find_if(
        data.begin(), 
        data.end(),
        [](int number) { return number % 5 == 0; }
    );

    if(itr == data.end() ){
        std::cout << "Such element does not exist\n";
    }else{
        int pos = std::distance(data.begin(),itr);
        std::cout<< "Element Position: "<<pos<< " Element: "<<*itr<<"\n";
    }



    //Example 04: Find employee with matching ID
    auto itr1 = std::find_if(  
        emp_data.begin(), 
        emp_data.end(),
        
        [](const EmployeePointer emp){
            return emp->id() == 102;
        }
    );
    if (itr1 == emp_data.end() ){
        std::cout << "This ID does not exist\n";
    }else {
        int pos = std::distance(emp_data.begin(),itr1);
        std::cout<<"Employee Found at Position "<<pos 
        << " and Element is: "<<**itr1<<"\n";
    }



    //Example 05: Count the data values where condition matches
    std::cout<<"Count of Elements Divisible By 5: ";
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [](int number) {return number % 5 == 0;}
    )<<std::endl;



    auto minSalary = std::min_element(
        emp_data.begin(),
        emp_data.end(),
        [](const EmployeePointer& a, const EmployeePointer& b) {
            return a->salary() < b->salary();
        }
    );
    std::cout<<"Minimum salary: "<<**minSalary<<std::endl;



    auto maxSalary = std::max_element(
        emp_data.begin(),
        emp_data.end(),
        [](const EmployeePointer& a, const EmployeePointer& b) {
            return a->salary() < b->salary();
        }
    );
    std::cout<<"Maximum salary: "<<**maxSalary<<std::endl;



    Container searchPattern;
    searchPattern.emplace_back(
        std::make_shared<Employee>(103, 129000.0f)
    );
    auto searchResult = std::search(
        emp_data.begin(),
        emp_data.end(),
        searchPattern.begin(),
        searchPattern.end(),
        [](const EmployeePointer& a, const EmployeePointer& b) {
            return a->id() == b->id() && a->salary() == b->salary();
        }
    );
    if (searchResult != emp_data.end()) {
        std::cout << "Search pattern found at position: " << std::distance(emp_data.begin(), searchResult) << std::endl;
    } else {
        std::cout << "Search pattern not found." << std::endl;
    }

}


// week 1: (10%)
// --------------
// q1 : 20%
// q2 : 35%
// q3 : 45%
// --------------
// 30/30

// quiz 1 5 % UML
// quiz 2 5 % 

// --------------
// week 2: (15%)
// --------------
// q1 : 20%
// q2 : 35%
// q3 : 45%
// -------
// 30/30

// Modern CPP Q1 : HORRIBLE
// Modern CPP Q2 : AVERAGE
// Modern CPP Q3 : GOOD


/*
    1)std::copy : copy all elements from source to destination
    2)std::copy_if : conditional copy elements from source to destination
            - requires resize using distance
    3) accumulate : performing binary operation on answer upto 
        current point by using one element from container
            - rolling binary operation
            - product, sum and even average

    4) any_of, all_of, none_of : check condition , return true or false
        (any element, all elements, no elements)

    5) std::min_element : return the position of the element 
            which is minimum (based on comparator if required)

    6) std::find_if : returns position of first instance matching
    condition. END is returned if element is not found

    7) std::sort : performs in-place sorting using random access iterators

    8) std::count_if :  return the counting of instances matching with
        condition

    9) std::distance : Gives difference between 2 iterators
    
*/