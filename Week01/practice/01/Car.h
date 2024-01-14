#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<memory>
#include"CarType.h"
#include"Engine.h"

class Car{
    private:
        std::string carID;
        std::string carBrand;
        CarType carType;
        std::shared_ptr<Engine> carEngine;
        float carPrice;
    public:
        Car()=default;

        Car(const Car&)=delete;
        Car& operator=(const Car&)=delete;

        Car(Car&&)=delete;
        Car& operator=(Car&&)=delete;

        Car(std::string id, std::string brand, CarType type, std::shared_ptr<Engine> engine, float price);

        ~Car()=default;

        std::string getCarID() const { return carID; }
        void setCarID(const std::string &carID_) { carID = carID_; }

        std::string getCarBrand() const { return carBrand; }
        void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

        CarType getCarType() const { return carType; }
        void setCarType(const CarType &carType_) { carType = carType_; }

        float getCarPrice() const { return carPrice; }
        void setCarPrice(float carPrice_) { carPrice = carPrice_; }

        std::shared_ptr<Engine> getCarEngine() const { return carEngine; }
        void setCarEngine(const std::shared_ptr<Engine> &carEngine_) { carEngine = carEngine_; }

        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
