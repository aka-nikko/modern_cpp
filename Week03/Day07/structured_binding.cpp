#include<iostream>
#include<array>
#include<tuple>

int main(){
    std::array<int,3> arr{101,70000,0};
    /*
        Old Method
    */
    int id=arr[0];
    int salary=arr[1];
    int gender=arr[2];

    /*
        Structured Binding
    */
    auto [_id, _salary, _gender]=arr;

    std::cout<<_id<<std::endl;

    std::tuple<int, float, std::string> tup{200, 100.0f, "Nikko"};
    
    return 0;
}