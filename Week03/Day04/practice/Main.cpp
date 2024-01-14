#include"Functionalities.h"

int main(){
    Container mydata;
    CreateObjects(mydata);

    //Display All Data
    std::cout<<"All Vehicles:\n";
    for(VType& vehicle:mydata){
        std::visit(
            [](auto&& val){std::cout<<*val<<std::endl;},
            vehicle
        );
    }

    //Display Average Price of All Vehicles
    try{
        std::cout<<"\nAverage Price of Vehicles : ";
        float averagePrice=AveragePrice(mydata);
        std::cout<<averagePrice<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    }

    //Check if the ID given by user exists in the data
    try{
        std::cout<<"Check If Given ID Exists  : ";
        bool ifIdExist = IfIdExist(mydata, "101");
        std::cout<<std::boolalpha<<ifIdExist<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    }

    //Display Vehicle with Minumum Price
    try{
        std::cout<<"Vehicle with Minimum Price:";
        VType minPriceInstance = MinimumPriceInstance(mydata);
        std::visit(
            [](auto&& val){std::cout<<*val<<std::endl;},
            minPriceInstance
        );
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    }
    
    //Display all vehicles with VehicleType given by user
    try{
        std::cout<<"Vehicles With Given Type  :\n";
        std::optional<std::list<VType>> matchingInstances=InstanceMatchingType(mydata, VehicleType::COMMUTE);
        if(matchingInstances.has_value()){
            for(VType& vehicle:matchingInstances.value()){
                std::visit(
                    [](auto&& val){std::cout<<*val<<std::endl;},
                    vehicle
                );
            }
        }else std::cout<<"No Vehicles Found With Given Type"<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    }

    return 0;
}