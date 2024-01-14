/*
    Create an array of 5 threads that calculate the square
    of ONE NUMBER FROM AN ARRAY of 5 integers, store
    answers in a result container.
*/

#include<iostream>
#include<thread>
#include<array>
#include<functional>

void InstantiateThreads(
        std::array<std::thread, 5>& threadArr,
        std::function<void(int, int)>f1,
        std::array<int, 5>& data
    ){
    auto itr=data.begin();
    for(int i=0;i<5;i++){
        threadArr[i]=std::thread(f1, *itr++,i);
    }
}

void JoinThreads(std::array<std::thread, 5>& threadArr){
    //Join Thread to Block Main
    for(std::thread& t:threadArr){
        if(t.joinable()){
            t.join();
        }
    }
}

void DisplayResult(std::array<int, 5>& data, std::array<int, 5>& result){
    //Display
    auto itr=data.begin();
    for(int val:result){
        if(itr!=data.end()){
            std::cout<<"Square of "<<*itr<<" is: "<<val<<std::endl;
            itr++;
        }
    }
}

void StartApp(){
    std::array<int, 5> data{10,20,30,40,50};
    std::array<int, 5> result;

    auto f1=[&](int number, int index){result[index]=number*number;};

    std::array<std::thread, 5> threadArr;
    InstantiateThreads(threadArr, f1, data);
    JoinThreads(threadArr);
    DisplayResult(data, result);
}

int main(){
    StartApp();
    return 0;
}