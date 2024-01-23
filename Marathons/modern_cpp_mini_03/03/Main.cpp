#include"Functionalities.h"

int main(){
    BrandContainer data;
    CreateObjects(data);

    //Display all data
    for(auto& brand : data){
        std::cout<<*brand<<std::endl;
    }


    //License Registation Prices Function Call
    try{
        std::cout << "\nLicense Registration Prices:" << std::endl;
        FindLicenseRegistrationPrices(data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Chassis for Brands with Given BrandType
    try{
        BrandType targetBrandType = BrandType::SPECIAL_PURPOSE;
        std::vector<CarChassis> chassisByType = GetChassisByType(data, targetBrandType);
        std::cout << "\nChassis for brands with BrandType " << static_cast<int>(targetBrandType) << ":" << std::endl;
        for (const auto& chassis : chassisByType) {
            std::cout << static_cast<int>(chassis) << " ";
        }
        std::cout << std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function call for Car Details of cars having price above threshold
    try{
        float priceThreshold = 55000.0;
        std::future<std::vector<CarDetails>> futureDetails = std::async(std::launch::async, GetCarsAboveThreshold, data, priceThreshold);
        std::vector<CarDetails> aboveThresholdDetails = futureDetails.get();
        std::cout << "\nCar details for cars above the threshold price of " << priceThreshold << ":" << std::endl;
        for (const auto& details : aboveThresholdDetails) {
            std::cout << "Brand: " << details.brandName << ", Seat Count: " << details.seatCount << ", Price: " << details.carPrice << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to print Chassis of car with highest price
    try{
        std::cout<<std::endl;
        PrintHighestPriceChassis(data);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to print if all cars have seat above 4
    try{
        std::cout << "\nAre all seats above 4 in each brand? " << std::boolalpha;
        for (const auto& brand : data) {
            std::cout << "Brand " << brand->uniqueTm() << ": " << AreAllSeatsAboveFour(brand) << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };

    return 0;
}

