#ifndef EVCAR_H
#define EVCAR_H

#include"Vehicle.h"
#include<iostream>

class EvCar: public Vehicle{
    private:
        int _battery_percentage;

    public:
        EvCar()=default;

        EvCar(const EvCar&)=delete;
        EvCar& operator=(const EvCar&)=delete;

        EvCar(EvCar&&)=delete;
        EvCar& operator=(EvCar&&)=delete;

        EvCar(int id, std::string name, float price, VehicleType type, int battery);
        EvCar(int id, std::string name, VehicleType type, int battery);

        void CalculateRegistrationCharge() override;
        void display() override;

        ~EvCar()=default;

        int batteryPercentage() const { return _battery_percentage; }

        friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
