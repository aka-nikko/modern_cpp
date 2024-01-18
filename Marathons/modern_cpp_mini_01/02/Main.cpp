#include"Functionalities.h"

int main(){
    Container mydata;

    CreateObjects(mydata);
    DisplayObjects(mydata);


    std::cout<<"\nID of Devices With Drain Factor Above 0.3:"<<std::endl;
    try{
        std::vector<std::string> IDs = IDFromBatteryDrainFactor(mydata);
        for(std::string& deviceID:IDs){
            std::cout<<deviceID<<" ";
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\n\nCheck if All Devices are INFOTAINMENT or NOT:"<<std::endl;
    try{
        if(CheckIfINFOTAINMENT(mydata)){
            std::cout<<"All Devices are INFOTAINMENT"<<std::endl;
        }else{
            std::cout<<"All Devices are Not INFOTAINMENT"<<std::endl;
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\nAverage Size of Devices with Release Quarter Q1 or Q4:"<<std::endl;
    try{
        float AverageSizeInBytes = AverageOfSize(mydata);
        std::cout<<AverageSizeInBytes<<std::endl;
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\nVersion Number of Given Device ID:"<<std::endl;
    try{
        std::cout<<VersionFromDeviceID(mydata, "101")<<std::endl;
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    std::cout<<"\nDevice Driver Container With Given Type:"<<std::endl;
    try{
        DriverContainer all_drivers = DriverFromType(mydata, DeviceType::INFOTAINMENT);
        for(auto& instance: all_drivers){
            std::cout<<*instance<<std::endl;
        }
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    return 0;
}