#ifndef BIKE_H
#define BIKE_H

#include<iostream>
#include"VehicleType.h"

class Bike{
    private:
        std::string _id;
        float _price;
        VehicleType _type;

    public:
        //Default Constructor
        Bike()=delete;

        //Copy Constructor
        Bike(const Bike&)=delete;

        //Copy Assignment Operator
        Bike& operator=(const Bike&)=delete;

        //Move Constructor
        Bike(Bike&&)=delete;

        //Move Assignment Operator
        Bike& operator=(Bike&&)=delete;

        //Destructor
        ~Bike()=default;

        //Parameterized Constructor
        Bike(std::string id, float price, VehicleType type);
        Bike(std::string id, float price);

        //Getter Functions
        std::string id() const { return _id; }
        float price() const { return _price; }
        VehicleType type() const { return _type; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H