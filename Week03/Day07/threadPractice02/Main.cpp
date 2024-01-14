#include"Functionalities.h"
#include<future>

int main(){
    Container mydata;
    Container result;
    EngineContainer engineData;

    CreateCarObjects(mydata, engineData);
    CreateEvTruckObjects(mydata);

    // std::cout<<"All Objects:"<<std::endl;
    // DisplayObjects(mydata);

    std::cout<<"Searched Vehicle: "<<std::endl;
    std::thread searchVehicleByIdThread(
        [&](){
            try{
                std::shared_ptr<Vehicle> searchedVehicle=SearchVehicleById(mydata, "101");
                std::cout<<*searchedVehicle<<std::endl;
            }catch(std::runtime_error msg){
                std::cout<<msg.what();
            };
        }
    );
    searchVehicleByIdThread.join();

    std::future<std::shared_ptr<Vehicle>> thread=std::async(
        std::launch::async,
        [&](){
            try{
                return SearchVehicleById(mydata, "101");
            }catch(std::runtime_error msg){
                std::cout<<msg.what();
                return std::shared_ptr<Vehicle>(nullptr);
            };
        }
    );
    std::shared_ptr<Vehicle> search=thread.get();
    if(search){
        std::cout<<*search<<std::endl;
    }

    

    // std::cout<<"Count of Given Vehicle: ";
    // // <<CountOfGivenVehicle(mydata, "Car")<<std::endl;
    // std::future<int> countOfGivenVehiclesThread = std::async(std::launch::async,[&](){
    //     try{
    //         return CountOfGivenVehicle(mydata,"Carw");
    //     }catch(std::runtime_error msg){
    //         std::cout<<msg.what();
    //         return 0;
    //     };
    // });
    // std::cout<<countOfGivenVehiclesThread.get()<<std::endl;



    // std::cout<<"Average Price of Given Vehicle: "
    // <<AveragePriceOfGivenVehicle(mydata, "Car")<<std::endl;

    // std::cout<<"Vehicle with Given Conditions:\n"<<std::endl;
    // result = RegistrationChargeCondition(mydata);
    // for(auto veh : result){
    //     std::cout<<*veh<<std::endl;
    // }

    return 0;
}