#include"Functionalities.h"

void CreateObjects(Container & data){
    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Nikko",
            "101",
            500000.0f,
            "Pheonix",
            "Pune",
            Grade::A,
            50
        )
    );

    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Anshul",
            "102",
            340000.0f,
            "Alpha",
            "Pune",
            Grade::B,
            30
        )
    );

    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Rahul",
            "103",
            200000.0f,
            "Beta",
            "Shimla",
            Grade::C,
            45
        )
    );
}

void InvokeCalculateBonus(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& emp:data){
        std::cout<<emp->CalculateBonus()<<std::endl;
    }
}

void DisplayEmployeeWithMaxSalary(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    auto maxSalary = std::max_element(
        data.begin(),
        data.end(),
        [](const Pointer& a, const Pointer& b) {
            return a->salary() < b->salary();
        }
    );
    std::cout<<"Maximum salary Employee:\n "<<**maxSalary<<std::endl;
}

void AllEmployeeLocationsOfGivenGrade(const Container& data, std::future<Grade>& ft) {
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    Grade targetGrade = ft.get();
    auto hasTargetGrade = [targetGrade](const Pointer& emp) {
        return emp->grade() == targetGrade;
    };
    std::vector<std::string> locations;

    std::for_each(data.begin(), data.end(), [&](const Pointer& emp) {
        if (hasTargetGrade(emp)) {
            locations.push_back(emp->employeeLocation());
        }
    });

    for (const auto& location : locations) {
        std::cout << "Employee Location: " << location << std::endl;
    }
}

std::string ProjectNameOfGivenID(const Container & data, std::future<std::string>& ft){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::string targetID = ft.get();
    auto hasTargetID = [targetID](const Pointer& emp) {
        return emp->id() == targetID;
    };
    auto it = std::find_if(data.begin(), data.end(), hasTargetID);

    if (it != data.end()) {
        return (*it)->projectName();
    } else {
        return "Not Found";
    }
}