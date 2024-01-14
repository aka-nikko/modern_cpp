#include"Insurance.h"

Insurance::Insurance(std::string id, float amount, InsuranceType itype):
    insuranceID(id), insuranceAmount(amount), insuranceType(itype){}

std::ostream &operator<<(std::ostream &os, const Insurance &rhs) {
    os << "insuranceID: " << rhs.insuranceID
       << " insuranceAmount: " << rhs.insuranceAmount
       << " insuranceType: " << static_cast<int>(rhs.insuranceType);
    return os;
}

