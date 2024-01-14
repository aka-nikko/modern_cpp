#include "Functionalities.h"

void CreateObjects(Vehicle **arr, const int size){
    // arr[0]=new Vehicle(101,"Maruti Dzire",850000.0f,VehicleType::PERSONAL);
    int id=0;
    std::string name="";
    float price=0.0f;
    VehicleType type=VehicleType::PERSONAL;
    int choice=-1;

    for(int i=0;i<size;i++){
        std::cin>>id;
        std::cin>>name;
        std::cin>>price;
        std::cin>>choice;

        if(choice==0){
            type=VehicleType::PERSONAL;
        }else if(choice==1){
            type=VehicleType::SECURITY;
        }else if(choice==2){
            type=VehicleType::TRANSPORT;
        }else{
            type=VehicleType::PERSONAL;
        }

        arr[i]=new Vehicle(id,name,price,type);
    }
}

float AveragePrice(Vehicle **arr, const int size){
    float total=0.0f;

    for(int i=0;i<size;i++){
        total+=arr[i]->price();
    }
    return total/size;
}

int LowestPriceId(Vehicle **arr, const int size){
    //Assume first location is minimum.
    int ans=arr[0]->id();
    float _min_price=arr[0]->price();

    for(int i=0;i<size;i++){
        float _current_price=arr[i]->price();

        if(_current_price<_min_price){
            _min_price=_current_price;
            ans=arr[i]->id();
        }
    }
    return ans;
}
