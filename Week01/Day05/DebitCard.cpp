#include"DebitCard.h"

DebitCard::DebitCard(int cvv, std::string dname, std::string expiry, DebitCardType dtype):
    _cvv(cvv), _name_on_card(dname), _expiry(expiry), _type(dtype){}

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_cvv: " << rhs._cvv
       << " _name_on_card: " << rhs._name_on_card
       << " _expiry: " << rhs._expiry
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}

