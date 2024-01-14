#ifndef EVTRUCK_H
#define EVTRUCK_H

#include<iostream>
#include"Vehicle.h"

class EvTruck : public Vehicle{
    private:
        int _batteryCapacity;

    public:
        //Default Constructor
        EvTruck()=delete;

        //Parameterized Constructor
        EvTruck(std::string id, std::string manufacturer, float price, int batteryCapacity);

        //Copy Constructor
        EvTruck(const EvTruck&)=delete;

        //Copy Assignment Operator
        EvTruck& operator=(const EvTruck&)=delete;

        //Move Constructor
        EvTruck(EvTruck&&)=delete;

        //Move Assignment Operator
        EvTruck& operator=(EvTruck&&)=delete;

        //Destructor
        ~EvTruck()=default;
        
        //Virtual Function
        float CalculateRegistrationCharges();

        //Getter Functions
        int batteryCapacity() const { return _batteryCapacity; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const EvTruck &rhs);
};

#endif // EVTRUCK_H
