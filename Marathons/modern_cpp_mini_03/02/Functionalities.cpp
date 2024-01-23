#include"Functionalities.h"

void CreateObjects(CabContainer & data){
    data.emplace_back(
        std::make_shared<CabRide>(
            101,
            CabRideType::LOCAL,
            PaymentMode::CARD,
            3000.0f,
            "Shimla",
            "BCS"
        )
    );

    data.emplace_back(
        std::make_shared<CabRide>(
            "102",
            CabRideType::OUTSTATION,
            PaymentMode::UPI,
            3400.0f,
            "Shimla",
            "BCS"
        )
    );

    data.emplace_back(
        std::make_shared<CabRide>(
            "103",
            CabRideType::LOCAL,
            PaymentMode::CARD,
            3000.0f,
            "Shimla",
            "BCS"
        )
    );

    data.emplace_back(
        std::make_shared<CabRide>(
            "104",
            CabRideType::LOCAL,
            PaymentMode::CARD,
            3000.0f,
            "Shimla",
            "BCS"
        )
    );

    data.emplace_back(
        std::make_shared<CabRide>(
            "105",
            CabRideType::LOCAL,
            PaymentMode::CARD,
            3000.0f,
            "Shimla",
            "BCS"
        )
    );
}

PaymentMode ReturnPaymentModeOfGivenCabID(const CabContainer& data, int id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    for(auto& cab : data){
        if(std::holds_alternative<int>(cab->id())){
            const int p =std::get<int>(cab->id());
            if(p==id){
                return cab->mode();
            }
        }else{
            const std::string p =std::get<std::string>(cab->id());
        }
    }

    throw std::runtime_error("Not Found");
}

std::array<PaymentMode, 2> FindMaxMinFarePaymentModes(const CabContainer& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is Empty!");
    }

    auto maxFareItr = std::max_element(data.begin(), data.end(),
        [](const CabPointer& cab1, const CabPointer& cab2) {
            return cab1->fare() < cab2->fare();
        });

    auto minFareItr = std::min_element(data.begin(), data.end(),
        [](const CabPointer& cab1, const CabPointer& cab2) {
            return cab1->fare() < cab2->fare();
        });

    if (maxFareItr != data.end() && minFareItr != data.end()) {
        std::array<PaymentMode, 2> result;

        result[0] = (*minFareItr)->mode(); // Minimum fare payment mode
        result[1] = (*maxFareItr)->mode(); // Maximum fare payment mode

        return result;
    } else {
        throw std::runtime_error("Error finding max/min fare");
    }
}

std::vector<std::string> GetLastNPickupLocations(const CabContainer& data, int N) {
    std::vector<std::string> pickupLocations;

    if (N > data.size()) {
        throw std::out_of_range("N is greater than the size of the container");
    }

    for (int i = data.size() - N; i < data.size(); ++i) {
        pickupLocations.push_back(data[i]->pickupLocation());
    }

    return pickupLocations;
}