#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Brand.h"
#include<vector>
#include<thread>
#include<future>
#include<algorithm>

using CarPointer=std::shared_ptr<Car>;
using CarContainer=std::array<CarPointer,3>;

using BrandPointer=std::shared_ptr<Brand>;
using BrandContainer=std::vector<BrandPointer>;


//Function to create 3 instances of Brand
void CreateObjects(BrandContainer& data);

float CalculateLicenseRegistrationPrice(const BrandPointer& brand);

void FindLicenseRegistrationPrices(const BrandContainer& data);

std::vector<CarChassis> GetChassisByType(const BrandContainer& data, BrandType type);

struct CarDetails {
    std::string brandName;
    int seatCount;
    float carPrice;
};
std::vector<CarDetails> GetCarsAboveThreshold(const BrandContainer& data, float threshold);

void PrintHighestPriceChassis(const BrandContainer& data);

bool AreAllSeatsAboveFour(const BrandPointer& brand);

#endif // FUNCTIONALITIES_H
