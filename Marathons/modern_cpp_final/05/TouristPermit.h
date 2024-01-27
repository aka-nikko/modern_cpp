#ifndef TOURISTPERMIT_H
#define TOURISTPERMIT_H

#include<iostream>

class TouristPermit{
    private:
        int _duration_months;
        std::string _permit_issuer_state;
        float _permit_cost;

    public:
        //Default Constructor
        TouristPermit()=delete;

        //Parameterized Constructor
        TouristPermit(int duration_months, std::string permit_issuer_state, float permit_cost);

        //Copy Constructor
        TouristPermit(const TouristPermit&)=delete;

        //Copy Assignment Operator
        TouristPermit& operator=(const TouristPermit&)=delete;

        //Move Constructor
        TouristPermit(TouristPermit&&)=delete;

        //Move Assignment Operator
        TouristPermit& operator=(TouristPermit&&)=delete;

        //Destructor
        ~TouristPermit()=default;

        //Getter Functions
        int durationMonths() const { return _duration_months; }
        std::string permitIssuerState() const { return _permit_issuer_state; }
        float permitCost() const { return _permit_cost; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const TouristPermit &rhs);
};

#endif // TOURISTPERMIT_H
