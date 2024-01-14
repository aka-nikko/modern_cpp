#include"Functionalities.h"

int main(){
    Container mydata;
    Engine eng1("1000001",EngineType::ICT,10,50);
    Engine eng2("1000002",EngineType::HYBRID,20,70);
    Engine eng3("1000003",EngineType::HYBRID,21,85);
    CreateObjects(mydata, eng1, eng2, eng3);
    DisplayObjects(mydata);

    // try{
    //     std::cout<<"Horse Power       : "<<FindHorsePowerByCarID(mydata, "101")<<std::endl;
    // }catch(std::runtime_error& msg){
    //     std::cout<<msg.what();
    // }

    // try{
    //     std::cout<<"Torque Above 80   : ";
    //     auto torqueabove80=TorqueAbove80(mydata);
    //     for(const auto& car:torqueabove80){
    //         std::cout<<car->getCarID()<<" ";
    //     }
    //     std::cout<<std::endl;
    // }catch(std::runtime_error& msg){
    //     std::cout<<msg.what();
    // }
    
    // try{
    //     std::cout<<"All Sports Cars   : ";
    //     auto carsofgiventype=CarsOfGivenType(mydata, CarType::SPORTS);
    //     for(const auto& car:carsofgiventype){
    //         std::cout<<car.getEngineNumber()<<" ";
    //     }
    //     std::cout<<std::endl;
    // }catch(std::runtime_error& msg){
    //     std::cout<<msg.what();
    // }
    
    // std::cout<<"Average HorsePower: "<<AverageHorsePower(mydata)<<std::endl;

    // std::cout<<"Lowest Price Car  : "<<LowestPriceCarID(mydata)<<std::endl;

    // std::cout<<"Combimed Price    : "<<CombinedPrice(mydata[0],mydata[1])<<std::endl;
    
    return 0;
}