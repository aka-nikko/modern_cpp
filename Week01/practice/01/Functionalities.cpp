#include"Functionalities.h"

void CreateObjects(Container& data){
    int num, cartype, hp, torque, engtype;
    std::string id, brand, number;
    float price;
    CarType cartypee;
    EngineType enginetype;
    std::cout<<"Enter Number of Objects to Create: ";
    std::cin>>num;

    for(int i=0;i<num;i++){
        std::cout<<"Enter Car "<<i+1<<" Details:\n";
        std::cout<<"Car ID           : ";
        std::cin>>id;
        std::cout<<"Car Brand        : ";
        std::cin>>brand;
        std::cout<<"Car Type Options :\n0-SEDAN\n1-SUV\n2-SPORTS\n3-HATCHBACK\nEnter Type       : ";
        std::cin>>cartype;
        switch (cartype){
        case 0:
            cartypee=CarType::SEDAN;
            break;
        case 1:
            cartypee=CarType::SUV;
            break;
        case 2:
            cartypee=CarType::SPORTS;
            break;
        case 3:
            cartypee=CarType::HATCHBACK;
            break;
        }
        std::cout<<"Car Price        : ";
        std::cin>>price;

        std::cout<<"Engine Number    : ";
        std::cin>>number;
        std::cout<<"Engine Options   :\n0-ICT\n1-HYBRID\nEnter Type       : ";
        std::cin>>engtype;
        switch (engtype){
        case 0:
            enginetype=EngineType::ICT;
            break;
        case 1:
            enginetype=EngineType::HYBRID;
            break;
        }
        std::cout<<"Engine HorsePower: ";
        std::cin>>hp;
        std::cout<<"Engine Torque    : ";
        std::cin>>torque;
        std::cout<<std::endl;

        data.emplace_back(
            std::make_shared<Car>(
                id,
                brand,
                cartypee,
                std::make_shared<Engine>(
                    number,
                    enginetype,
                    hp,
                    torque
                ),
                price
            )
        );
    }
    
}

int FindHorsePowerByCarID(const Container & data, const std::string id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->getCarID()==id){
            return ptr->getCarEngine()->getEngineHorsepower();
        }
    }

    throw std::runtime_error("ID Not Found\n");
}

Container TorqueAbove80(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    Container newdata;
    for(const Pointer& ptr:data){
        if(ptr->getCarEngine()->getEngineTorque()>80){
            newdata.emplace_back(ptr);
        }
    }
    
    if(newdata.empty()){
        throw std::runtime_error("No Car with Torque More Than 80\n");
    }
    return newdata;
}

EngineContainer CarsOfGivenType(const Container & data, CarType type){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    EngineContainer newdata;
    for(const Pointer& ptr:data){
        if(ptr->getCarType()==type){
            newdata.emplace_back(ptr->getCarEngine());
        }
    }

    if(newdata.empty()){
        throw std::runtime_error("No Cars with Given Type\n");
    }
    return newdata;
}

float AverageHorsePower(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    float total=0.0f;
    int count=0;
    for(const Pointer& ptr:data){
        if(ptr->getCarEngine()->getEngineType()==EngineType::ICT && ptr->getCarPrice()>1000000){
            total=total+ptr->getCarEngine()->getEngineHorsepower();
            count++;
        }
    }
    return total/count;
}

std::string LowestPriceCarID(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    Pointer lowest=data.front();
    for(const Pointer& ptr:data){
        if(ptr->getCarPrice()<lowest->getCarPrice()){
            lowest=ptr;
        }
    }
    return lowest->getCarID();
}

float CombinedPrice(Pointer & car1, Pointer & car2){
    float totalPrice = car1->getCarPrice()+car2->getCarPrice();
    return totalPrice;
}

void DisplayObjects(const Container& data){
    for(const auto& car:data){
        std::cout<<*car<<std::endl;
    }
}