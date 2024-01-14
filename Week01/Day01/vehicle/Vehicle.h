#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"VehicleType.h"

class Vehicle{
    private:
        int _id;
        std::string _model_name;
        float _price;
        VehicleType _type;
        
    public:
        Vehicle(int id, std::string model, float price, VehicleType type);

        //1. Default Constructor (Deleted Default Constructor)
        //Functionality not required. Disable it.
        Vehicle()=delete;

        //2. Copy Constructor (Deleted Copy Constructor)
        Vehicle(const Vehicle&)=delete;

        //3. Copy Assugnment Operator
        Vehicle& operator=(const Vehicle&)=delete;

        //4. Move Constructor
        Vehicle(Vehicle&&)=delete;

        //5. Move Assignment
        Vehicle& operator=(Vehicle&&)=delete;

        //6. Destructor
        ~Vehicle()=default;

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        int id() const { return _id; }
        void setId(int id) { _id = id; }
};

#endif // VEHICLE_H
