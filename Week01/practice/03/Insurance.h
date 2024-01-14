#ifndef INSURANCE_H
#define INSURANCE_H

#include<iostream>
#include"InsuranceType.h"

class Insurance{
private:
    std::string insuranceID;
    float insuranceAmount;
    InsuranceType insuranceType;
    
public:
    Insurance()=default;

    Insurance(std::string id, float amount, InsuranceType itype);

    Insurance(const Insurance&)=delete;
    Insurance& operator=(const Insurance&)=default;

    Insurance(const Insurance&&)=delete;
    Insurance& operator=(const Insurance&&)=delete;


    ~Insurance()=default;

    std::string getInsuranceID() const { return insuranceID; }
    void setInsuranceID(const std::string &insuranceID_) { insuranceID = insuranceID_; }

    float getInsuranceAmount() const { return insuranceAmount; }
    void setInsuranceAmount(float insuranceAmount_) { insuranceAmount = insuranceAmount_; }

    InsuranceType getInsuranceType() const { return insuranceType; }
    void setInsuranceType(const InsuranceType &insuranceType_) { insuranceType = insuranceType_; }

    friend std::ostream &operator<<(std::ostream &os, const Insurance &rhs);
};

#endif // INSURANCE_H
