#include<iostream>
#include<array>

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
    
    return 0;
}