#include"BusinessOwner.h"

BusinessOwner::BusinessOwner(float expense_amount, float revenue, 
                            std::string registered_business_name, 
                            BusinessType business_type):
    _expense_amount(expense_amount), _revenue(revenue), 
    _registered_business_name(registered_business_name),
    _business_type(business_type) {}

std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
    os << "_expense_amount: " << rhs._expense_amount
       << " _revenue: " << rhs._revenue
       << " _registered_business_name: " << rhs._registered_business_name
       << " _business_type: " << static_cast<int>(rhs._business_type);
    return os;
}

