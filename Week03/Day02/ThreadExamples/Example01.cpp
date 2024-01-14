/*
    Create athread that calculates squares of all numbers
    in an array ans stores them in a result container
*/

#include<iostream>
#include<thread>
#include<array>

int main(){
    std::array<int, 5> data{10,20,30,40,50};
    std::array<int, 5> result;

    /*
        Create and instantiate t1
    */
    std::thread t1(
        //Function
        [&result](std::array<int,5>& data){
            int k=0;
            for(int val:data){
                result[k++]=val*val;
            }
        },
        //Argument
        std::ref(data)
    );

    /*
        Wait for t1
    */
    t1.join();

    /*
        Display Output
    */
    auto itr=data.begin();
    for(int val:result){
        if(itr!=data.end()){
            std::cout<<"Square of "<<*itr<<" is: "<<val<<std::endl;
            itr++;
        }
    }

    return 0;
}