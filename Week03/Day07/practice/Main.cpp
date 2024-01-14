#include"Functionalities.h"
#include<thread>

int main(){
    Container mydata;
    CreateObjects(mydata);

    std::cout<<"Display Data:"<<std::endl;
    for(auto& var : mydata){
        std::cout<<*var<<std::endl;
    }

    std::cout<<"Calculate Tax:"<<std::endl;
    std::thread calculateTaxPayableThread(
        CalculateTaxPayable,
        std::ref(mydata)
    );

    std::cout<<"Call Paren Operator For Average of Goods Price:"<<std::endl;
    std::thread callParenOperatorThread(
        CallParenOperator,
        std::ref(mydata)
    );

    calculateTaxPayableThread.join();
    callParenOperatorThread.join();
    return 0;
}