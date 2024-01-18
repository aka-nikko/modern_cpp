#include"Functionalities.h"

int main(){
    Container mydata;
    CreateObjects(mydata);

    std::cout<<"All Objects:"<<std::endl;
    DisplayObjects(mydata);

    std::cout<<"\nID of Order With Highest Discount:"<<std::endl;
    try{
        std::string HighestDiscount = HighestDiscountID(mydata);
        std::cout<<HighestDiscount<<std::endl;
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\nOrderType of Order ID 101:"<<std::endl;
    try{
        OrderType TypeFromID = OrderTypeFromID(mydata, "101");
        switch (static_cast<int>(TypeFromID)){
        case 0:
            std::cout<<"Type: PAID"<<std::endl;
            break;
        case 1:
            std::cout<<"Type: COD"<<std::endl;
            break;
        case 2:
            std::cout<<"Type: PROMOTION"<<std::endl;
            break;
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }
    
    std::cout<<"\nAverage of All Values of Order:"<<std::endl;
    try{
        std::cout<<AverageOfValues(mydata)<<std::endl;
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\nFirst N Instances:"<<std::endl;
    try{
        Container n_instances = FirstNInstances(mydata, 3);
        for(const auto& instance: n_instances){
            std::cout<<*instance<<std::endl;
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    return 0;
}