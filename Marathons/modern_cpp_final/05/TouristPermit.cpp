#include"TouristPermit.h"

TouristPermit::TouristPermit(int duration_months, std::string permit_issuer_state, float permit_cost):
    _duration_months(duration_months), _permit_issuer_state(permit_issuer_state),
    _permit_cost(permit_cost) {}

std::ostream &operator<<(std::ostream &os, const TouristPermit &rhs) {
    os << "_duration_months: " << rhs._duration_months
       << " _permit_issuer_state: " << rhs._permit_issuer_state
       << " _permit_cost: " << rhs._permit_cost;
    return os;
}
