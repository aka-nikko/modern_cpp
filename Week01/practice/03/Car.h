#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"Vehicle.h"
#include"CarType.h"
#include"Car.h"

class Car: public Vehicle{
private:
    CarType carType;
    float carPrice;
    std::string carColor;

public:
    Car()=delete;
    Car(std::string id, int registration, VehicleType vtype, Insurance& insuranceplan, CarType ctype, float price, std::string color);

    Car(const Car&)=delete;
    Car& operator=(const Car&)=delete;

    Car(const Car&&)=delete;
    Car& operator=(const Car&&)=delete;

    void printDetails() override{};

    ~Car()=default;

    CarType getCarType() const { return carType; }
    void setCarType(const CarType &carType_) { carType = carType_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    std::string getCarColor() const { return carColor; }
    void setCarColor(const std::string &carColor_) { carColor = carColor_; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

};

#endif // CAR_H
