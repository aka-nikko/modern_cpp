#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

std::mutex mt;
std::condition_variable cv;

/*
    DisplaySquare
        - It should print the square of the number received as input from user

    Main
        - Main will take cin input and store value in a global variable.
*/

int number=0;
bool flag=false;

void Square(){
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [](){return flag;});
    std::cout<<"Square of Number is: "<<number*number<<std::endl;
}

int main(){
    std::thread t1(&Square);

    std::cin>>number;

    flag=true;  //this specifies the condition is met

    cv.notify_one(); //Signal sent from main to OS that we can now 
                     //invoke the waiting thread
    t1.join();

    return 0;
}