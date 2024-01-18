#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Device.h"
#include<memory>
#include<vector>

using Pointer = std::shared_ptr<Device>;
using Container = std::vector<Pointer>;
using DriverContainer = std::vector<std::shared_ptr<DeviceDriver>>;

//Function to Create Objects
void CreateObjects(Container& data);

//Function to Display Objects
void DisplayObjects(Container& data);

//Function to Return Device ID of Devices
//having _battery_drain_factor above 0.3
std::vector<std::string> IDFromBatteryDrainFactor(Container& data);

//Function to Check if all Devices are INFOTAINMENT type or Not
bool CheckIfINFOTAINMENT(Container& data);

//Function to Return Average of _size_in_bytes of
// devices having _release_quarter as Q1 or Q4
float AverageOfSize(Container& data);

//Function to Return _version_number from given DeviceID
std::string VersionFromDeviceID(Container& data, std::string id);

//Function to Return Container of DeviceDriver of given Type
DriverContainer DriverFromType(Container& data, DeviceType type);

#endif // FUNCTIONALITIES_H
