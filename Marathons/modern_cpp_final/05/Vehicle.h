#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<memory>
#include<variant>
#include"Owner.h"
#include"TouristPermit.h"
#include"PrivatePermit.h"

using OwnerPointer = std::shared_ptr<Owner>;
using OwnerRef = std::reference_wrapper<OwnerPointer>;

using TouristPointer=std::shared_ptr<TouristPermit>;
using PrivatePointer=std::shared_ptr<PrivatePermit>;
using VType=std::variant<TouristPointer, PrivatePointer>;

class Vehicle{
    private:
        int _id;
        float _price;
        OwnerRef _owner;
        VType _permit;

    public:
        //Default Constructor
        Vehicle()=delete;

        //Parameterized Constructor
        Vehicle(int id, float price, OwnerRef owner, VType permit);

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

        //Getter Functions
        int id() const { return _id; }
        float price() const { return _price; }
        OwnerRef owner() const { return _owner; }
        const VType& permit() const { return _permit; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
