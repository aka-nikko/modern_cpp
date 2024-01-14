#include<iostream>
#include<thread>
#include<array>

std::array<int,10> result;

void square(std::array<int,5>& data){
    int k=0;
    for(int val:data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++]=val*val;
    }
}

void cube(std::array<int,5>& data){
    int k=5;
    for(int val:data){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        result[k++]=val*val*val;
    }
}

int main(){
    std::array<int,5> data{1,2,3,4,5};
    square(data);
    cube(data);

    for(int val:result){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}