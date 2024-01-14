#include<iostream>
#include"Vehicle.h"
#include"Functionalities.h"

int main(){
    const int size=3;
    Vehicle* arr[3]={nullptr};
    CreateObjects(arr,size);
    /*
        Average price should be calculated for
        all instances stored in the array by CreateObjects
    */
    float avg = AveragePrice(arr,size);
    std::cout<<"Average Price  : "<<avg<<std::endl;

    /*
        Minimum Price Function
    */
    int min_id=LowestPriceId(arr,size);
    std::cout<<"Lowest Price ID: "<<min_id<<std::endl;

    return 0;
}