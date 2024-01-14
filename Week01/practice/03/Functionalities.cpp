#include"Functionalities.h"

void CreateObjects(VehicleContainer& data, Insurance& ins1, Insurance& ins2){
    data.emplace_back(
        std::make_shared<Car>(
            "101",
            2023,
            VehicleType::PRIVATE,
            ins1,
            CarType::SUV,
            600000.0f,
            "Black"
        )
    );

    data.emplace_back(
        std::make_shared<Car>(
            "102",
            2023,
            VehicleType::COMMERCIAL,
            ins2,
            CarType::HATCHBACK,
            800000.0f,
            "Black"
        )
    );
}

void DisplayObjects(VehicleContainer& data){
    for(const auto& vehicle:data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle))
            std::cout<<*mycar<<std::endl;
    }
}

CarContainer InsuranceOverThreshold(VehicleContainer & data, float amount){
    CarContainer newdata;
    if(data.empty()){
        throw std::runtime_error("Data is Empty!!");
    }
    
    for(const auto& vehicle:data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
            if(mycar->getVehicleInsurancePlan().getInsuranceAmount()>amount){
                newdata.emplace_back(mycar);
            }
        }
    }

    if(newdata.empty()){
        throw std::runtime_error("No Cars Are Above Threshold!!\n");
    }

    return newdata;
}

std::vector<float> CarPricesOfVehicleType(VehicleContainer& data, VehicleType type){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!!");
    }

    std::vector<float> carPrices;
    for(const auto& vehicle:data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
            if(mycar->getVehicleType()==type){
                carPrices.emplace_back(mycar->getCarPrice());
            }
        }
    }

    return carPrices;
}

std::vector<std::string> CarColorOfPrivateVehicle(VehicleContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!!");
    }

    std::vector<std::string> carColors;
    for(const auto& vehicle:data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
            if(mycar->getVehicleType()==VehicleType::PRIVATE){
                carColors.emplace_back(mycar->getCarColor());
            }
        }
    }

    return carColors;
}

float AverageInsuranceAmount(VehicleContainer & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!!");
    }

    float totalPrice=0.0f;
    int count=0;
    for(const auto& vehicle:data){
        if(auto mycar=std::dynamic_pointer_cast<Car>(vehicle)){
            if(mycar->getVehicleType()==VehicleType::COMMERCIAL && mycar->getVehicleRegistration()==2023 && mycar->getVehicleInsurancePlan().getInsuranceType()==InsuranceType::ZERO_DEBT){
                totalPrice=totalPrice+mycar->getCarPrice();
                count++;
            }
        }
    }

    if(count==0){
        throw std::runtime_error("No Vehicle Satisfies Conditions!!\n");
    }

    return totalPrice/count;
}