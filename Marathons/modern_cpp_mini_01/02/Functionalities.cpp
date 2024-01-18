#include"Functionalities.h"

void CreateObjects(Container& data){
    data.emplace_back(
        std::make_shared<Device>(
            "101",
            DeviceType::ACCESSORY,
            40,
            std::make_shared<DeviceDriver>(
                "10001",
                ReleaseQuarter::Q1,
                1024.0f
            )
        )
    );

    data.emplace_back(
        std::make_shared<Device>(
            "102",
            DeviceType::INFOTAINMENT,
            54,
            std::make_shared<DeviceDriver>(
                "10002",
                ReleaseQuarter::Q2,
                6546.0f
            )
        )
    );

    data.emplace_back(
        std::make_shared<Device>(
            "103",
            DeviceType::INFOTAINMENT,
            65,
            std::make_shared<DeviceDriver>(
                "10003",
                ReleaseQuarter::Q3,
                4354.0f
            )
        )
    );

    data.emplace_back(
        std::make_shared<Device>(
            "104",
            DeviceType::SAFETY,
            23,
            std::make_shared<DeviceDriver>(
                "10004",
                ReleaseQuarter::Q2,
                3245.0f
            )
        )
    );

    data.emplace_back(
        std::make_shared<Device>(
            "105",
            DeviceType::ACCESSORY,
            76,
            std::make_shared<DeviceDriver>(
                "10005",
                ReleaseQuarter::Q4,
                7432.0f
            )
        )
    );
}

void DisplayObjects(Container& data){
    for(const auto& device:data){
        std::cout<<*device<<std::endl;
    }
}

std::vector<std::string> IDFromBatteryDrainFactor(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    std::vector<std::string> IDContainer;

    for(const auto& device:data){
        if(device->_battery_drain_factor()>0.3f){
            IDContainer.emplace_back(device->deviceId());
        }
    }

    if(IDContainer.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    return IDContainer;
}

bool CheckIfINFOTAINMENT(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }
    
    for(const auto& device:data){
        if(device->deviceType()!=DeviceType::INFOTAINMENT){
            return false;
        }
    }

    return true;
}

float AverageOfSize(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    float total = 0.0f;
    int count = 0;
    for(const auto& device:data){
        if(device->deviceDriver()->releaseQuarter()==ReleaseQuarter::Q1 || device->deviceDriver()->releaseQuarter()==ReleaseQuarter::Q4){
            total = total+device->deviceDriver()->sizeInBytes();
            count++;
        }
    }

    return total/count;
}

std::string VersionFromDeviceID(Container & data, std::string id){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& device:data){
        if(device->deviceId()==id){
            return device->deviceDriver()->versionNumber();
        }
    }

    throw std::runtime_error("ID Not Found!!");
}

DriverContainer DriverFromType(Container & data, DeviceType type){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    DriverContainer drivers;

    for(const auto& device:data){
        if(device->deviceType()==type){
            drivers.emplace_back(device->deviceDriver());
        }
    }

    if(drivers.empty()){
        throw std::runtime_error("No Drivers of Given Type!!");
    }

    return drivers;
}