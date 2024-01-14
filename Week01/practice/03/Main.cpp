#include"Functionalities.h"

int main(){
    VehicleContainer mydata;
    Insurance ins1("101", 50000.0f, InsuranceType::REGULAR);
    Insurance ins2("102", 60000.0f, InsuranceType::ZERO_DEBT);
    CreateObjects(mydata, ins1, ins2);
    // DisplayObjects(mydata);

    try{
        CarContainer aboveThreshold=InsuranceOverThreshold(mydata, 50000.0f);
        for(const auto car:aboveThreshold){
            std::cout<<*car<<std::endl;
        }
    }catch(std::runtime_error &msg){
        std::cout<<msg.what()<<std::endl;
    }

    try{
        std::vector<float> carPrices=CarPricesOfVehicleType(mydata, VehicleType::PRIVATE);
        for(const auto car:carPrices){
            std::cout<<car<<std::endl;
        }
    }catch(std::runtime_error &msg){
        std::cout<<msg.what()<<std::endl;
    }

    try{
        std::vector<std::string> carColors=CarColorOfPrivateVehicle(mydata);
        for(const auto car:carColors){
            std::cout<<car<<std::endl;
        }
    }catch(std::runtime_error &msg){
        std::cout<<msg.what()<<std::endl;
    }

    try{
        float averagePrice = AverageInsuranceAmount(mydata);
        std::cout<<averagePrice<<std::endl;
    }catch(std::runtime_error &msg){
        std::cout<<msg.what()<<std::endl;
    }

    return 0;
}