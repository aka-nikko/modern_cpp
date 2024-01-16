#include"Functionalities.h"
#include<future>

int main(){
    Container mydata;
    Container result;
    EngineContainer engineData;

    CreateCarObjects(mydata, engineData);
    CreateEvTruckObjects(mydata);

    std::cout<<"All Objects:"<<std::endl;
    DisplayObjects(mydata);

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


    std::cout<<"Vehicle with Given ID: "<<std::endl;
    try{
        std::future<std::shared_ptr<Vehicle>> thread1=std::async(
            std::launch::async,
            &SearchVehicleById,
            std::ref(mydata),
            "101"
        );
        std::cout<<*(thread1.get())<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    std::cout<<"Count of Given Vehicle: ";
    try{
        std::promise<std::string> pr;
        std::future<std::string> ft=pr.get_future();

        std::future<int> thread2 = std::async(
            std::launch::async,
            &CountOfGivenVehicle,
            std::ref(mydata),
            std::ref(ft)
        );

        pr.set_value("Car");

        std::cout<<thread2.get()<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    std::cout<<"Average Price of Given Vehicle: ";
    try{
        std::future<float> thread3 = std::async(
            std::launch::async,
            &AveragePriceOfGivenVehicle,
            std::ref(mydata),
            "Car"
        );
        std::cout<<thread3.get()<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    std::cout<<"Vehicle with Given Conditions:"<<std::endl;
    try{
        std::future<Container> thread4 = std::async(
            std::launch::async,
            &RegistrationChargeCondition,
            std::ref(mydata)
        );
        result=thread4.get();
        for(auto veh : result){
            std::cout<<*veh<<std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    return 0;
}