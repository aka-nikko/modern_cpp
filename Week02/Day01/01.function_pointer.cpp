#include<iostream>

void operation(void (*logic)(int), int data){
    logic(data);
}

void square(int number){
    std::cout<<number*number<<std::endl;
}

void cube(int number){
    std::cout<<number*number*number<<std::endl;
}

void times100(int number){
    std::cout<<number*100<<std::endl;
}

void percent_10(int number){
    std::cout<<(int)(number*0.1f)<<std::endl;
}

int main(){
    //A Function pointer (Whihc points to a function)
    //TYPE of ptr is signature of function
    void (*ptr)(int)=&square;

    //Function pointer can be reassigned to function with same signature
    ptr=&cube;

    operation(square, 5);
    operation(cube, 7);
    operation(times100, 3);
    operation(percent_10, 80);

    return 0;
}