#include"DeviceDriver.h"

DeviceDriver::DeviceDriver(std::string version, ReleaseQuarter release, float size):
    _version_number(version), _release_quarter(release), _size_in_bytes(size){}

std::ostream &operator<<(std::ostream &os, const DeviceDriver &rhs) {
    os << "_version_number: " << rhs._version_number
       << " _release_quarter: " << static_cast<int>(rhs._release_quarter)
       << " _size_in_bytes: " << rhs._size_in_bytes;
    return os;
}
