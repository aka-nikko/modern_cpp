#include<iostream>
//Variadic Templates (templates that can accept variable number of aruments)
//eg. make_shared

//Use concept of recurssion and base case

template<typename T>
T add(T n1){
    return n1;
}

template<typename T, typename... Args>
auto add(T n1, Args... args){
    return n1+add(args...);
}

int main(){
    std::cout<<add(10,20,30)<<std::endl;
    std::cout<<add(10,30)<<std::endl;
    
    return 0;
}