#include<iostream>
#include<functional>

void operation(std::function<void(int)> logic, int data){
    logic(data);
}

int main(){

    operation([](int number){std::cout<<number*number<<std::endl;}, 5);
    operation([](int number){std::cout<<number*number*number<<std::endl;}, 7);
    operation([](int number){std::cout<<number*100<<std::endl;}, 3);
    operation([](int number){std::cout<<(int)(number*0.1f)<<std::endl;}, 80);

    return 0;
}