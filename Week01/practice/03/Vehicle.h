#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<memory>
#include"VehicleType.h"
#include"Insurance.h"

class Vehicle{
private:
    std::string vehicleID;
    int vehicleRegistration;
    VehicleType vehicleType;
    Insurance& vehicleInsurancePlan;

public:
    Vehicle()=default;
    Vehicle(std::string id, int registration, VehicleType vtype, Insurance& insuranceplan);

    Vehicle(const Vehicle&)=delete;
    Vehicle& operator=(const Vehicle&)=delete;

    Vehicle(const Vehicle&&)=delete;
    Vehicle& operator=(const Vehicle&&)=delete;

    virtual void printDetails()=0;

    ~Vehicle()=default;

    std::string getVehicleID() const { return vehicleID; }
    void setVehicleID(const std::string &vehicleID_) { vehicleID = vehicleID_; }

    int getVehicleRegistration() const { return vehicleRegistration; }
    void setVehicleRegistration(int vehicleRegistration_) { vehicleRegistration = vehicleRegistration_; }

    VehicleType getVehicleType() const { return vehicleType; }
    void setVehicleType(const VehicleType &vehicleType_) { vehicleType = vehicleType_; }

    Insurance& getVehicleInsurancePlan() const { return vehicleInsurancePlan; }
    void setVehicleInsurancePlan(const Insurance& vehicleInsurancePlan_) { vehicleInsurancePlan = vehicleInsurancePlan_; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
