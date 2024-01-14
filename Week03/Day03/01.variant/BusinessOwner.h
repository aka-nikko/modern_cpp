#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include<iostream>

class BusinessOwner{
    private:

    public:
        BusinessOwner(){}
        ~BusinessOwner(){}

        void PayTax(){
            std::cout<<"Business had to pay advanced tax and GST every month"<<std::endl;
        }
};


#endif // BUSINESSOWNER_H
