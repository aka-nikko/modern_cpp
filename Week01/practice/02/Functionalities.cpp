#include"Functionalities.h"

void CreateObjects(Container& data, Engine& eng1, Engine& eng2, Engine& eng3){
    data.emplace_back(
        std::make_shared<Car>(
            "101",
            "Honda",
            CarType::SPORTS,
            eng1,
            1200000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "102",
            "Mahindra",
            CarType::HATCHBACK,
            eng2,
            2500000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "103",
            "BMW",
            CarType::SPORTS,
            eng3,
            5000000.0f
        )
    );
}

int FindHorsePowerByCarID(const Container & data, const std::string id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->getCarID()==id){
            return ptr->getCarEngine().getEngineHorsepower();
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
        if(ptr->getCarEngine().getEngineTorque()>80){
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
        if(ptr->getCarEngine().getEngineType()==EngineType::ICT && ptr->getCarPrice()>1000000){
            total=total+ptr->getCarEngine().getEngineHorsepower();
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