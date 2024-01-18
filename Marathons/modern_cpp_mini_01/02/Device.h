#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>
#include<memory>
#include"DeviceType.h"
#include"DeviceDriver.h"

class Device{
private:
    std::string _device_id;
    DeviceType _device_type;
    int _device_battery_level;
    std::shared_ptr<DeviceDriver> _device_driver;

public:
    //Default Constructor
    Device()=delete;

    //Parameterized Constructor
    Device(std::string id, DeviceType type, int battery, std::shared_ptr<DeviceDriver> driver);

    //Copy Constructor
    Device(const Device&)=delete;

    //Copy Assignment Operator
    Device& operator=(const Device&)=delete;

    //Move Constructor
    Device(const Device&&)=delete;

    //Move Assignment Operator
    Device& operator=(const Device&&)=delete;

    //Function to Return _battery_drain_factor
    float _battery_drain_factor(){
        if(_device_type==DeviceType::INFOTAINMENT || _device_type==DeviceType::SAFETY){
            return 0.25f;
        }else{
            if(_device_battery_level>50){
                return 0.5f;
            }else return 0.4f;
        }
    }

    //Default Destructor
    ~Device()=default;

    //Getter and Setter Functions
    std::string deviceId() const { return _device_id; }
    void setDeviceId(const std::string &device_id) { _device_id = device_id; }

    DeviceType deviceType() const { return _device_type; }
    void setDeviceType(const DeviceType &device_type) { _device_type = device_type; }

    int deviceBatteryLevel() const { return _device_battery_level; }
    void setDeviceBatteryLevel(int device_battery_level) { _device_battery_level = device_battery_level; }

    std::shared_ptr<DeviceDriver> deviceDriver() const { return _device_driver; }
    void setDeviceDriver(const std::shared_ptr<DeviceDriver> &device_driver) { _device_driver = device_driver; }

    //Insertions Operator (<<) Overloaded
    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
};

#endif // DEVICE_H
