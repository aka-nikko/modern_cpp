#ifndef PRIVATEPERMIT_H
#define PRIVATEPERMIT_H

#include<iostream>
#include"PrivateCategory.h"

class PrivatePermit{
    private:
        std::string _permit_issuer_state;
        float _permit_tax;
        int _permit_renewal_charge;
        PrivateCategory _private_permit_category;

    public:
        //Default Constructor
        PrivatePermit()=delete;

        //Parameterized Constructor
        PrivatePermit(std::string permit_issuer_state, float permit_tax, 
        int permit_renewal_charge, PrivateCategory private_permit_category);

        //Copy Constructor
        PrivatePermit(const PrivatePermit&)=delete;

        //Copy Assignment Operator
        PrivatePermit& operator=(const PrivatePermit&)=delete;

        //Move Constructor
        PrivatePermit(PrivatePermit&&)=delete;

        //Move Assignment Operator
        PrivatePermit& operator=(PrivatePermit&&)=delete;

        //Destructor
        ~PrivatePermit()=default;

        //Getter Functions
        std::string permitIssuerState() const { return _permit_issuer_state; }
        float permitTax() const { return _permit_tax; }
        int permitRenewalCharge() const { return _permit_renewal_charge; }
        PrivateCategory privatePermitCategory() const { return _private_permit_category; }

        friend std::ostream &operator<<(std::ostream &os, const PrivatePermit &rhs);

        //Stream Output Operator
};

#endif // PRIVATEPERMIT_H
