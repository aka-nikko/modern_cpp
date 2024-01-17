#include<iostream>
#include<set>
#include<memory>
#include"Employee.h"

template<typename T>
void Display(const T& container){
    for(const auto& val : container){
        std::cout<<val<<std::endl;
    }
}

using Pointer=std::shared_ptr<Employee>;
using PointerContainer=std::set<Pointer>;

template <typename T>
void CreateData(T& container) {
    container.emplace(
        std::make_shared<Employee>(101, 89000.0f)
    );

    container.emplace(
        std::make_shared<Employee>(102, 189000.0f)
    );

    container.emplace(
        std::make_shared<Employee>(103, 129000.0f)
    );
}

template<>
void Display(const PointerContainer& container){
    for(const Pointer& ptr : container){
        std::cout<<*ptr<<std::endl;
    }
}

int main(){
    std::set<int> s1{10, 20, 30, 40, 50, 10};
    Display<std::set<int>>(s1);

    PointerContainer mydata;
    CreateData(mydata);

    Display<std::set<Pointer>>(mydata);
    
    return 0;
}