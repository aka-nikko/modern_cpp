#include"Response.h"

std::ostream &operator<<(std::ostream &os, const Response &rhs) {
    os << "_response_string: " << rhs._response_string
       << " _response_status_code: " << rhs._response_status_code
       << " _elapsed_time_since_execution: " << rhs._elapsed_time_since_execution;
    return os;
}
