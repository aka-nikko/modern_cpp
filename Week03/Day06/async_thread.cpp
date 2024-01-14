#include<iostream>
#include<future>

/*
    A   B   C

    Single Thread Technique
    Option 01: One after the other. Always complete one thing before 
                strating the next task.
    
    Multi-threaded Approach
    Option 02: I will complete all tasks in such a way that i 
                "practically stat all of themat the same time" but
                keep juggling them based on some criteria.
    
    Parallel Execution
    Option 03: Map number of tasks amongst number of "workers"

    Asynchronous Execution
    Option 04: Start a task. Either delegate it to another worker OR do 
                it yourself after some time.
                If someone else is doing a task, monitor it, wait for their
                work to be done, take follow-up actions accordingly.
*/

/*
    2 Tasks:
    Calculate Factorial of 5
    Calculate square of a number given by the user
*/

int square(std::future<int>& ft){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Hello from square. I have started my work"<<std::endl;
    int number=ft.get();
    return number*number;
}

int factorial(int number){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    if(number<0){
        throw std::runtime_error("Negative Number Error!");
    }else if(number==0||number==1){
        return 1;
    }else{
        return number*factorial(number-1);
    }
}

int main(){
    //Step 01: Make a Promise
    std::promise<int> pr;

    //Step 02: A future link to the promise
    std::future<int> ft=pr.get_future();

    /*
        OS: Launch square (if possible as a new thread)
    */
    std::future<int> result_ft=std::async(std::launch::async, &square, std::ref(ft));

    int val=0;
    std::cin>>val;
    pr.set_value(val);
    std::cout<<factorial(5)<<std::endl;
    
    std::cout<<"Result of Square is: "<<result_ft.get()<<std::endl;

    return 0;
}

/*
    client-server architecture

    future-promise model

    square calculation:
    Main needs to delegate the task of square calculation.
    ---> A new thread for square will be registered with OS
*/