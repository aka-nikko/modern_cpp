#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>

class Vehicle{
    private:
        std::string _id;
        std::string _manufacturer;
        float _price;

    public:
        //Default Constructor
        Vehicle()=default;

        //Parameterized Constructor
        Vehicle(std::string id, std::string manufacturer, float price);

        //Copy Constructor
        Vehicle(const Vehicle&)=delete;

        //Copy Assignment Operator
        Vehicle& operator=(const Vehicle&)=delete;

        //Move Constructor
        Vehicle(Vehicle&&)=delete;

        //Move Assignment Operator
        Vehicle& operator=(Vehicle&&)=delete;

        //Destructor
        ~Vehicle()=default;

        //Pure Virtual Function
        virtual float CalculateRegistrationCharges()=0;

        //Getter Functions
        std::string id() const { return _id; }
        std::string manufacturer() const { return _manufacturer; }
        float price() const { return _price; }

        friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

        //Stream Output Operator
};

#endif // VEHICLE_H
