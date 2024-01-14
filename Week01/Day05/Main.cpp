#include"Functionalities.h"

int main(){
    //Empty Container
    Container mydata;

    CreateObjects(mydata);
    std::cout<<"Average Age of all Customers: "<<AverageAge(mydata)<<std::endl;

    try{
        std::cout<<"ID of Customer Number 02    : "<<NthCustomer(mydata, 2)->id()<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    }

    std::cout<<"Age of Customer with ID 112 : "<<AgeOfGivenCustomerID(mydata, 112)<<std::endl;

    std::cout<<"CVV of Customer with ID 112 : "<<CVVOfGivenCustomerID(mydata, 112)<<std::endl;

    std::cout<<"Expiry of Card with CVV 102 : "<<ExpiryOfGivenCardCVV(mydata, 102)<<std::endl;

    try{
        std::cout<<"Customer Above Age 50:\n";
        Container newcon = CustomersAgeAbove50(mydata);
        for(const Pointer& data:newcon){
            std::cout<<*data<<"\n";
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what();
    }

    std::cout<<"Card of Customer with ID 102: \n"<<*CardOfGivenID(mydata, 112)<<std::endl;

    return 0;
}