#ifndef DIESELCAR_H
#define DIESELCAR_H

#include"Vehicle.h"
#include<iostream>

class DieselCar: public Vehicle{
    private:
        int _fuel_tank_capacity;
    public:
        DieselCar()=default;

        DieselCar(const DieselCar&)=delete;
        DieselCar& operator=(const DieselCar&)=delete;

        DieselCar(DieselCar&&)=delete;
        DieselCar& operator=(DieselCar&&)=delete;

        DieselCar(int id, std::string name, float price, VehicleType type, int capacity);
        DieselCar(int id, std::string name, VehicleType type, int capacity);

        void CalculateRegistrationCharge() override;
        void display() override;

        ~DieselCar()=default;

        int fuelTankCapacity() const { return _fuel_tank_capacity; }

        friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);
};

#endif // DIESELCAR_H
