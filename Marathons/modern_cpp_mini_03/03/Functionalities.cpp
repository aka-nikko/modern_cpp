#include"Functionalities.h"

void CreateObjects(BrandContainer& data) {
    // Creating Car instances
    CarPointer car1 = std::make_shared<Car>(5, 50000.0, CarChassis::CARBON_FIBER);
    CarPointer car2 = std::make_shared<Car>(4, 60000.0, CarChassis::STEEL);
    CarPointer car3 = std::make_shared<Car>(2, 70000.0, CarChassis::CARBON_FIBER);

    // Creating Brand instances with Car instances
    BrandPointer brand1 = std::make_shared<Brand>(BrandType::SPECIAL_PURPOSE, "BrandX", CarContainer{car1, car2, car3});
    BrandPointer brand2 = std::make_shared<Brand>(BrandType::CONSUMER, "BrandY", CarContainer{car2, car3, car1});
    BrandPointer brand3 = std::make_shared<Brand>(BrandType::TRANSPORT, "BrandZ", CarContainer{car3, car1, car2});

    // Adding the Brand instances to the BrandContainer
    data.emplace_back(brand1);
    data.emplace_back(brand2);
    data.emplace_back(brand3);
}

float CalculateLicenseRegistrationPrice(const BrandPointer& brand) {
    float totalPrice = 0.0f;

    for (const auto& car : brand->cars()) {
        totalPrice += car->price();
    }

    return totalPrice;
}

void FindLicenseRegistrationPrices(const BrandContainer& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::vector<std::future<float>> futures;

    for (const auto& brand : data) {
        futures.push_back(std::async(std::launch::async, CalculateLicenseRegistrationPrice, brand));
    }

    for (size_t i = 0; i < data.size(); ++i) {
        float licensePrice = futures[i].get();
        std::cout << "License registration price for " << data[i]->uniqueTm() << ":" << licensePrice << std::endl;
    }
}

std::vector<CarChassis> GetChassisByType(const BrandContainer& data, BrandType type) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::vector<CarChassis> chassisContainer;

    for (const auto& brand : data) {
        if (brand->type() == type) {
            for (const auto& car : brand->cars()) {
                chassisContainer.push_back(car->chasis());
            }
        }
    }

    return chassisContainer;
}

std::vector<CarDetails> GetCarsAboveThreshold(const BrandContainer& data, float threshold) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::vector<CarDetails> aboveThresholdDetails;

    for (const auto& brand : data) {
        for (const auto& car : brand->cars()) {
            if (car->price() > threshold) {
                aboveThresholdDetails.push_back({brand->uniqueTm(), car->seatCount(), car->price()});
            }
        }
    }

    return aboveThresholdDetails;
}


void PrintHighestPriceChassis(const BrandContainer& data) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float highestPrice = 0.0;
    CarChassis highestPriceChassis;

    for (const auto& brand : data) {
        for (const auto& car : brand->cars()) {
            if (car->price() > highestPrice) {
                highestPrice = car->price();
                highestPriceChassis = car->chasis();
            }
        }
    }

    std::cout << "Chassis details of the car with the highest price: " << std::endl;
    std::cout << "Highest Price: " << highestPrice << std::endl;
    std::cout << "Chassis: " << static_cast<int>(highestPriceChassis) << std::endl;
}


bool AreAllSeatsAboveFour(const BrandPointer& brand) {
    return std::all_of(brand->cars().begin(), brand->cars().end(), [](const CarPointer& car) {
        return car->seatCount() > 4;
    });
}