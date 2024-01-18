#include"Device.h"

Device::Device(std::string id, DeviceType type, int battery, std::shared_ptr<DeviceDriver> driver):
    _device_id(id), _device_type(type), _device_battery_level(battery), _device_driver(driver){}

std::ostream &operator<<(std::ostream &os, const Device &rhs) {
    os << "_device_id: " << rhs._device_id
       << " _device_type: " << static_cast<int>(rhs._device_type)
       << " _device_battery_level: " << rhs._device_battery_level
       << " _device_driver: " << *rhs._device_driver;
    return os;
}
