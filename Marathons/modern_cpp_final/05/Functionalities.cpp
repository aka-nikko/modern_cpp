#include"Functionalities.h"

void CreateObject(Container &data, OwnerContainer& owner) {
    owner.emplace_back(
        std::make_shared<Owner>(
            "Nikko", 
            "Shimla", 
            OwnerType::FULL_OWNER
        )
    );
    owner.emplace_back(
        std::make_shared<Owner>(
            "Anshul", 
            "Shimla", 
            OwnerType::PART_OWNER
        )
    );
    owner.emplace_back(
        std::make_shared<Owner>(
            "Rahul", 
            "Solan", 
            OwnerType::FULL_OWNER
        )
    );
    owner.emplace_back(
        std::make_shared<Owner>(
            "Raj", 
            "Pune", 
            OwnerType::PART_OWNER
        )
    );
    owner.emplace_back(
        std::make_shared<Owner>(
            "Nikhil", 
            "Mumbai", 
            OwnerType::FULL_OWNER
        )
    );
    
    data.emplace_back(
        std::make_shared<Vehicle>(
            101, 
            20000.0, 
            owner[0], 
            std::make_shared<TouristPermit>(
                6, 
                "HP", 
                1000.0
            )
        )
    );
    data.emplace_back(
        std::make_shared<Vehicle>(
            102, 
            450000.0, 
            owner[1], 
            std::make_shared<TouristPermit>(
                10, 
                "MP", 
                2000.0
            )
        )
    );
    data.emplace_back(
        std::make_shared<Vehicle>(
            103, 
            23000.0, 
            owner[2], 
            std::make_shared<TouristPermit>(
                3, 
                "AP", 
                1500.0
            )
        )
    );
    data.emplace_back(
        std::make_shared<Vehicle>(
            104, 
            540000.0, 
            owner[3], 
            std::make_shared<PrivatePermit>(
                "Sate1", 
                500.0, 
                50, 
                PrivateCategory::HMV
            )
        )
    );
    data.emplace_back(
        std::make_shared<Vehicle>(
            105, 
            500000.0, 
            owner[4], 
            std::make_shared<PrivatePermit>(
                "State2", 
                399.0, 
                45, 
                PrivateCategory::LMV
            )
        )
    );
}

void SearchAndDisplayById(const Container &data, int searchId) {
    auto foundVehicle = std::find_if(
        data.begin(), 
        data.end(), 
        [searchId](const VehiclePointer &vehicle) {
            return vehicle->id() == searchId;
        }
    );

    if (foundVehicle != data.end()) {
        std::cout<<"Vehicle with _id "<<searchId<<" found:"<<std::endl;
        std::cout<<"Permit details: ";
        
        std::visit(
            [&](auto&& permit) {
                std::cout<<*permit;
            }, 
            (*foundVehicle)->permit()
        );
        
        std::cout<<std::endl;
    } else {
        std::cout<<"Vehicle with _id "<<searchId<<" not found."<<std::endl;
    }
}

int CountVehiclesByOwnerType(const Container &data, OwnerType targetType) {
    return std::count_if(
        data.begin(), 
        data.end(), 
        [targetType](const VehiclePointer &vehicle) {
            return vehicle->owner().get()->type() == targetType;
        }
    );
}

bool AreAllPricesBelowThreshold(const Container &data, float threshold) {
    return std::all_of(
        data.begin(), 
        data.end(), 
        [threshold](const VehiclePointer &vehicle) {
            return vehicle->price() < threshold;
        }
    );
}

std::string FindPermitIssuerStateByName(const Container &data, const std::string &ownerName) {
    auto foundVehicle = std::find_if(
        data.begin(), 
        data.end(), 
        [ownerName](const VehiclePointer &vehicle) {
            return vehicle->owner().get()->name() == ownerName;
        }
    );

    if (foundVehicle != data.end()) {
        return std::visit(
            [](auto&& permit) {
                return permit->permitIssuerState();
            }, 
            (*foundVehicle)->permit()
        );
    } else {
        return "Owner not found";
    }
}

std::shared_ptr<Owner> FindOwnerDetailsById(const Container &data, int searchId) {
    auto foundVehicle = std::find_if(
        data.begin(), 
        data.end(), 
        [searchId](const VehiclePointer &vehicle) {
            return vehicle->id() == searchId;
        }
    );

    if (foundVehicle != data.end()) {
        return (*foundVehicle)->owner().get();
    } else {
        return nullptr;
    }
}

bool AreAllPermitIssuerStatesSame(const Container &data) {
    const auto& firstPermit = data.front()->permit();

    return std::all_of(
        data.begin(), 
        data.end(), 
        [&firstPermit](const VehiclePointer &vehicle) {
            return vehicle->permit() == firstPermit;
        }
    );
}

void FindAndDisplayMinMaxPermitTax(const Container &data) {
    float minPermitTax = std::numeric_limits<float>::max();
    float maxPermitTax = std::numeric_limits<float>::lowest();

    for (const auto &vehicle : data) {
        if (const auto* privatePermit = std::get_if<PrivatePointer>(&vehicle->permit())) {
            minPermitTax = std::min(minPermitTax, (*privatePermit)->permitTax());
            maxPermitTax = std::max(maxPermitTax, (*privatePermit)->permitTax());
        }
    }

    if (minPermitTax != std::numeric_limits<float>::max()) {
        std::cout<<"Minimum _permit_tax: "<<minPermitTax<<std::endl;
    } else {
        std::cout<<"No vehicles with PrivatePermit found."<<std::endl;
    }

    if (maxPermitTax != std::numeric_limits<float>::lowest()) {
        std::cout<<"Maximum _permit_tax: "<<maxPermitTax<<std::endl;
    }
}

float FindTotalTouristPermitCost(const Container &data) {
    float totalCost = std::accumulate(
        data.begin(), 
        data.end(), 
        0.0f, 
        [](float totalCost, const VehiclePointer &vehicle){
            if (auto* touristPermit = std::get_if<TouristPointer>(&vehicle->permit())) {
                totalCost   += (*touristPermit)->permitCost();
            }
            return totalCost;
        }
    );

    if (totalCost == 0.0f) {
        std::cout<<"No vehicles with TouristPermit found."<<std::endl;
    }

    return totalCost;
}