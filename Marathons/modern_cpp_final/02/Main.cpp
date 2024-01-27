#include"Functionalities.h"

int main() {
    Container data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Function to Print Odd Numbers from Container
    try{
        performOperation(OddNumbers, data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    //Function to Print Numbers Divisible by 4
    try{
        performOperation(DivisibleBy4,data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    //Function to Print Sum of Largest and Second Largest Numbers
    try{
        performOperation(SumOfTwoLargestNumbers,data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    //Function to Print Minimum Element
    try{
        performOperation(MinimumElement,data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    return 0;
}
