#include"Vehicle.h"

Vehicle::Vehicle(std::string id, int registration, VehicleType vtype, Insurance& insuranceplan):
    vehicleID(id), vehicleRegistration(registration), vehicleType(vtype), vehicleInsurancePlan(insuranceplan){}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "vehicleID: " << rhs.vehicleID
       << " vehicleRegistration: " << rhs.vehicleRegistration
       << " vehicleType: " << static_cast<int>(rhs.vehicleType)
       << " vehicleInsurancePlan: " << rhs.vehicleInsurancePlan;
    return os;
}

