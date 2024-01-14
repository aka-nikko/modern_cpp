#include"Functionalities.h"

void CreateObjects(Container& data){
    data.emplace_back(
        std::make_shared<Car>(
            "101",
            1000000.0f,
            VehicleType::HATCHBACK
        )
    );

    data.emplace_back(
        std::make_shared<Bike>(
            "201",
            230000.0f,
            VehicleType::COMMUTE
        )
    );

    data.emplace_back(
        std::make_shared<Car>(
            "102",
            3400000.0f,
            VehicleType::SEDAN
        )
    );

    data.emplace_back(
        std::make_shared<Bike>(
            "202",
            300000.0f,
            VehicleType::SPORTS
        )
    );
}

float AveragePrice(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float totalPrice=0.0f;
    for(const VType& vehicle:data){
        std::visit(
            [&](auto&& val){totalPrice=totalPrice+val->price();},
            vehicle
        );
    }
    return totalPrice/data.size();
}

VType MinimumPriceInstance(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float minPrice = std::visit([](auto& item){return item->price();},data.front());
    VType minInstance = data.front();

    for(const VType& vehicle:data){
        float currentPrice=std::visit(
            [&](auto&& val)->float{
                return val->price();
            },
            vehicle
        );

        if(currentPrice<minPrice){
            minPrice=currentPrice;
            minInstance=vehicle;
        }
    }
    
    return minInstance;
}

bool IfIdExist(const Container & data, std::string id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    bool flag=false;
    for(const VType& v:data){
        std::visit(
            [&](auto&& val){
                if(val->id()==id){
                    flag = true;
                }
            },
            v
        );
    }
    return flag;
}

std::optional<std::list<VType>> InstanceMatchingType(const Container& data, VehicleType type){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    Container result;
    for(const VType& v:data){
        std::visit(
            [&](auto&& val){
                if(val->type()==type){
                    result.push_back(val);
                }
            },
            v
        );
    }

    /*
        If result is empty even after for loop, it means no instance has a 
        matching type.
        Compiler should be notified that result has no valid value. Thats 
        why we send nullopt.
    */
    if(result.empty()){
        return std::nullopt;
    } else return result;
}