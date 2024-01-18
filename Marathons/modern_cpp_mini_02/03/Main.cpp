#include"Functionalities.h"

int main(){
    int choice;
    Container mydata;
    Container result;
    EngineContainer engineData;
    std::shared_ptr<Vehicle> searchedVehicle;
    std::string searchID;
    std::string vehicleToFind;

    while(1){
        std::cout<<"MAIN MENU:\n1.Create Object\n2.Display Objects\n3.Search By ID\n4.Vehicle Count\n5.Average Price\n6.Vehicles with Reg Charge >0 & <5000\n7.Exit\nEnter Choice: ";
        std::cin>>choice;
        switch(choice){
            case 1:
                int objectOf;
                std::cout<<"1.Car\n2.EvTruck\nEnter Choice: ";
                std::cin>>objectOf;
                switch(objectOf){
                    case 1:
                        CreateCarObjects(mydata, engineData);
                        break;

                    case 2:
                        CreateEvTruckObjects(mydata);
                        break;
                    
                    default:
                        break;
                }
                break;

            case 2:
                DisplayObjects(mydata);
                // for(auto vehicle : mydata){
                //     std::cout<<*vehicle<<std::endl;
                // }
                break;

            case 3:
                std::cout<<"Enter ID to Search: ";
                std::cin>>searchID;
                searchedVehicle=SearchVehicleById(mydata, searchID);
                std::cout<<*searchedVehicle<<std::endl;
                break;
            
            case 4:
                std::cout<<"Enter Vehicle (Car, EvTruck): ";
                std::cin>>vehicleToFind;
                std::cout<<"Count of Given Vehicle: "
                <<CountOfGivenVehicle(mydata, vehicleToFind)<<std::endl;
                break;

            case 5:
                std::cout<<"Enter Vehicle (Car, EvTruck): ";
                std::cin>>vehicleToFind;
                std::cout<<"Average Price of Given Vehicle: "
                <<AveragePriceOfGivenVehicle(mydata, vehicleToFind)<<std::endl;
                break;
            
            case 6:
                std::cout<<"Vehicle with Given Conditions:\n"<<std::endl;
                result = RegistrationChargeCondition(mydata);
                for(auto veh : result){
                    std::cout<<*veh<<std::endl;
                }
                break;

            case 7:
                exit(0);
                break;

            default:
                std::cout<<"Enter Valid Choice"<<std::endl;
                break;
        }
    }
    return 0;
}