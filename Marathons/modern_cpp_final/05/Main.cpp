#include"Functionalities.h"

int main(){
    Container mydata;
    OwnerContainer owner;
    CreateObject(mydata, owner);

    //Display all Objects
    for (const auto &vehicle : mydata) {
        std::cout << *vehicle << std::endl;
    }


    //Function to Search and Display Permit Details by Vehicle ID
    try{
        SearchAndDisplayById(mydata, 101);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Count Given Vehicle Type by Owner Type 
    try{
        OwnerType targetOwnerType = OwnerType::FULL_OWNER;
        int count = CountVehiclesByOwnerType(mydata, targetOwnerType);
        std::cout << "Number of vehicles with owner type " << static_cast<int>(targetOwnerType) << ": " << count << std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    //Function to Check if all Prices are Below Given Threshold
    try{
        float priceThreshold = 25000.0;
        bool allPricesBelowThreshold = AreAllPricesBelowThreshold(mydata, priceThreshold);
        if (allPricesBelowThreshold) {
            std::cout << "All vehicle prices are below the threshold." << std::endl;
        } else {
            std::cout << "Not all vehicle prices are below the threshold." << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Find Permit Issuer State By Owner Name
    try{
        std::string ownerNameToFind = "John Doe";
        std::string permitIssuerState = FindPermitIssuerStateByName(mydata, ownerNameToFind);
        std::cout << "Permit issuer state for owner " << ownerNameToFind << ": " << permitIssuerState << std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Find Owner Details by Vehicle ID
    try{
        std::shared_ptr<Owner> ownerDetails = FindOwnerDetailsById(mydata, 101);
        if (ownerDetails) {
            std::cout << "Owner details for vehicle with given ID:" << std::endl;
            std::cout << *ownerDetails << std::endl;
        } else {
            std::cout << "Vehicle with given id not found." << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Check if All Permit Issuer States are Same
    try{
        bool allSameIssuerState = AreAllPermitIssuerStatesSame(mydata);
        if (allSameIssuerState) {
            std::cout << "All vehicles have the same _permit_issuer_state." << std::endl;
        } else {
            std::cout << "Not all vehicles have the same _permit_issuer_state." << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Dislpay Max and Min Permit Tax
    try{
        FindAndDisplayMinMaxPermitTax(mydata);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Find Total Tourist Permit Cost
    try{
        float totalTouristPermitCost = FindTotalTouristPermitCost(mydata);
        if (totalTouristPermitCost > 0.0f) {
            std::cout << "Total _permit_cost from TouristPermit vehicles: " << totalTouristPermitCost << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };
    return 0;
}