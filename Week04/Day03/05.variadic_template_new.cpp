#include<iostream>

template<typename... T>
auto add(T... args){
    return (args+...);
}

int main(){
    std::cout<<add(10,20,30)<<std::endl;
    std::cout<<add(10,30)<<std::endl;
    
    return 0;
}