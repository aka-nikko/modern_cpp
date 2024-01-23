#include <iostream>
#include <thread>
#include <future>
#include"Functionalities.h"

int main() {
    CabContainer data;
    CreateObjects(data);
    

    int cabID = 101;
    // Async thread for ReturnPaymentModeOfGivenCabID
    std::future<PaymentMode> paymentModeFuture = std::async(ReturnPaymentModeOfGivenCabID, data, cabID);
    PaymentMode paymentModeResult = paymentModeFuture.get();
    std::cout << "Payment Mode for Cab ID " << cabID << ": " << static_cast<int>(paymentModeResult) << std::endl;



    // FindMaxMinFarePaymentModes function
    std::future<std::array<PaymentMode, 2>> maxMinFareModesFuture = std::async(FindMaxMinFarePaymentModes, data);
    std::array<PaymentMode, 2> maxMinFareModesResult = maxMinFareModesFuture.get();
    std::cout << "Minimum Fare Payment Mode: " << static_cast<int>(maxMinFareModesResult[0]) << std::endl;
    std::cout << "Maximum Fare Payment Mode: " << static_cast<int>(maxMinFareModesResult[1]) << std::endl;



    // GetLastNPickupLocations function
    int N = 2;  
    // Async thread for GetLastNPickupLocations
    std::future<std::vector<std::string>> pickupLocationsFuture = std::async(GetLastNPickupLocations, data, N);
    std::vector<std::string> pickupLocationsResult = pickupLocationsFuture.get();
    std::cout << "Pickup Locations of Last " << N << " Instances:\n";
    for (const auto& location : pickupLocationsResult) {
        std::cout << location << std::endl;
    }

    return 0;
}
