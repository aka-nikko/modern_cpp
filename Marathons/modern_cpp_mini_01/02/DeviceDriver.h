#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include<iostream>
#include"ReleaseQuarter.h"

class DeviceDriver{
private:
    std::string _version_number;
    ReleaseQuarter _release_quarter;
    float _size_in_bytes;

public:
    //Default Constructor
    DeviceDriver()=delete;

    //Parameterized Constructor
    DeviceDriver(std::string version, ReleaseQuarter release, float size);

    //Copy Constructor
    DeviceDriver(const DeviceDriver&)=delete;

    //Copy Assignment Operator
    DeviceDriver& operator=(const DeviceDriver&)=delete;

    //Move Constructor
    DeviceDriver(const DeviceDriver&&)=delete;

    //Move Assignment Operator
    DeviceDriver& operator=(const DeviceDriver&&)=delete;

    //Default Destructor
    ~DeviceDriver()=default;

    //Getter and Setter Functions
    std::string versionNumber() const { return _version_number; }
    void setVersionNumber(const std::string &version_number) { _version_number = version_number; }

    ReleaseQuarter releaseQuarter() const { return _release_quarter; }
    void setReleaseQuarter(const ReleaseQuarter &release_quarter) { _release_quarter = release_quarter; }

    float sizeInBytes() const { return _size_in_bytes; }
    void setSizeInBytes(float size_in_bytes) { _size_in_bytes = size_in_bytes; }

    //Overloaded Insersion Operator (<<)
    friend std::ostream &operator<<(std::ostream &os, const DeviceDriver &rhs);
};

#endif // DEVICEDRIVER_H
