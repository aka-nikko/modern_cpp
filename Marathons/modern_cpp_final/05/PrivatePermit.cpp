#include"PrivatePermit.h"

PrivatePermit::PrivatePermit(std::string permit_issuer_state, float permit_tax, 
        int permit_renewal_charge, PrivateCategory private_permit_category):
    _permit_issuer_state(permit_issuer_state),_permit_tax(permit_tax),
    _permit_renewal_charge(permit_renewal_charge), 
    _private_permit_category(private_permit_category) {}

std::ostream &operator<<(std::ostream &os, const PrivatePermit &rhs) {
    os << "_permit_issuer_state: " << rhs._permit_issuer_state
       << " _permit_tax: " << rhs._permit_tax
       << " _permit_renewal_charge: " << rhs._permit_renewal_charge
       << " _private_permit_category: " << static_cast<int>(rhs._private_permit_category);
    return os;
}
