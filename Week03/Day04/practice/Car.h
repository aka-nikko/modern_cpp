#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<string>
#include"VehicleType.h"

class Car{
    private:
        std::string _id;
        float _price;
        VehicleType _type;

    public:
        //Default Constructor
        Car()=delete;

        //Copy Constructor
        Car(const Car&)=delete;

        //Copy Assignment Operator
        Car& operator=(const Car&)=delete;

        //Move Constructor
        Car(Car&&)=delete;

        //Move Assignment Operator
        Car& operator=(Car&&)=delete;

        //Destructor
        ~Car()=default;

        //Parameterized Constructor
        Car(std::string id, float price, VehicleType type);
        Car(std::string id, float price);

        //Getter Functions
        std::string id() const { return _id; }
        float price() const { return _price; }
        VehicleType type() const { return _type; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H