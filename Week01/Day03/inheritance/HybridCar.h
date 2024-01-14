#ifndef HYBRIDCAR_H
#define HYBRIDCAR_H

#include"Vehicle.h"
#include<iostream>

class HybridCar: public Vehicle{
    private:
        int _fuel_tank_capacity;
        int _battery_percentage;

    public:
        HybridCar()=default;

        HybridCar(const HybridCar&)=delete;
        HybridCar& operator=(const HybridCar&)=delete;

        HybridCar(HybridCar&&)=delete;
        HybridCar& operator=(HybridCar&&)=delete;

        HybridCar(int id, std::string name, float price, VehicleType type, int capacity, int battery);
        HybridCar(int id, std::string name, VehicleType type, int capacity, int battery);

        void CalculateRegistrationCharge() override;
        void display() override;

        ~HybridCar()=default;

        int fuelTankCapacity() const { return _fuel_tank_capacity; }

        int batteryPercentage() const { return _battery_percentage; }

        friend std::ostream &operator<<(std::ostream &os, const HybridCar &rhs);
};

#endif // HYBRIDCAR_H
