#include"Functionalities.h"

int main(){
    EngineContainer mydata;
    CreateObjects(mydata);

    //Displat all Engine Data
    for(auto& var : mydata){
        std::cout<<*var<<std::endl;
    }


    //Function to Return Container of EngineTypes Satisfying Given Condition
    std::cout<<"Engine Types of All Instances Satisfying Condition: "<<std::endl;
    try{
        std::vector<EngineType> result=ReturnEngineTypesSatisfyingConditions(mydata);
        std::string type;
        for(auto& var : result){
            if(static_cast<int>(var)==0){
                type="PETROL";
            }else if(static_cast<int>(var)==1){
                type="DIESEL";
            }else if(static_cast<int>(var)==2){
                type="HYBRID";
            }
            std::cout<<type<<std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Check if All Instances Have Torque Above 110
    try{
        CheckIfAllTorqueAbove110(mydata);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Count Instances Over Given Engine Capacity
    try{
        CountInstancesOverGivenCapacity(mydata, 100.0f);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    return 0;
}