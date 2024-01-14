#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"

class Vehicle{
    private:
        int _id{-1};
        std::string _name{""};
        float _price{0.0f};
        VehicleType _type{VehicleType::PERSONAL};
        
    public:
        Vehicle()=default;

        Vehicle(const Vehicle&)=delete;
        Vehicle& operator=(const Vehicle&)=delete;

        Vehicle(Vehicle&&)=delete;
        Vehicle& operator=(Vehicle&&)=delete;

        Vehicle(int id, std::string name, float price, VehicleType type);
        Vehicle(int id, std::string name, VehicleType type);

        virtual void CalculateRegistrationCharge()=0;
        virtual void display();
        
        ~Vehicle()=default;

        int id() const { return _id; }

        std::string name() const { return _name; }

        float price() const { return _price; }

        VehicleType type() const { return _type; }

        friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};


#endif // VEHICLE_H
