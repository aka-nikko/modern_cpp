#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include<iostream>
#include"BusinessType.h"

class BusinessOwner{
    private:
        float _expense_amount;
        float _revenue;
        std::string _registered_business_name;
        BusinessType _business_type;

    public:
        //Default Constructor
        BusinessOwner()=delete;

        //Parameterized Constructor
        BusinessOwner(float expense_amount, float revenue, 
                    std::string registered_business_name, 
                    BusinessType business_type);

        //Copy Constructor
        BusinessOwner(const BusinessOwner&)=delete;

        //Copy Assignment Operator
        BusinessOwner& operator=(const BusinessOwner&)=delete;

        //Move Constructor
        BusinessOwner(BusinessOwner&&)=delete;

        //Move Assignment Operator
        BusinessOwner& operator=(BusinessOwner&&)=delete;

        //Destructor
        ~BusinessOwner()=default;

        //Getter Functions
        float expenseAmount() const { return _expense_amount; }
        float revenue() const { return _revenue; }
        std::string registeredBusinessName() const { return _registered_business_name; }
        BusinessType businessType() const { return _business_type; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_H
