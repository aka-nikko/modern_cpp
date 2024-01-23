#ifndef CABRIDE_H
#define CABRIDE_H

#include<iostream>
#include"CabRideType.h"
#include"PaymentMode.h"
#include<variant>
#include<any>

class CabRide{
    private:
        std::variant<int,std::string> _id;
        CabRideType _type;
        PaymentMode _mode;
        float _fare;
        std::string _drop_location;
        std::string _pickup_location;

    public:
        //Default Constructor
        CabRide()=delete;

        //Parameterized Constructor
        CabRide(std::variant<int,std::string>, CabRideType type, 
                PaymentMode mode, float fare, std::string drop_location, 
                std::string pickup_location);

        //Copy Constructor
        CabRide(const CabRide&)=delete;

        //Copy Assignment Operator
        CabRide& operator=(const CabRide&)=delete;

        //Move Constructor
        CabRide(CabRide&&)=delete;

        //Move Assignment Operator
        CabRide& operator=(CabRide&&)=delete;

        //Destructor
        ~CabRide()=default;

        //Getter Functions
        // const std::variant<int,std::string>& id() const { return std::visit([&](auto&& val){return val;},_id);}
        CabRideType type() const { return _type; }
        PaymentMode mode() const { return _mode; }
        float fare() const { return _fare; }
        std::string dropLocation() const { return _drop_location; }
        std::string pickupLocation() const { return _pickup_location; }

        const std::variant<int,std::string>& id() const { return _id; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const CabRide &rhs);
};

#endif // CABRIDE_H
