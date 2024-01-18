#include"Functionalities.h"

//Function To Create Objects
void CreateObjects(Container& data){
    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Nikko",
            "101",
            1200000.0f,
            std::make_shared<Department>(
                "10001",
                100
            ),
            "Pheonix",
            "Pune",
            Grade::A,
            80
        )
    );

    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Anshul",
            "102",
            2500000.0f,
            std::make_shared<Department>(
                "10002",
                50
            ),
            "Project",
            "Pune",
            Grade::B,
            58
        )
    );

    data.emplace_back(
        std::make_shared<FullTimeEmployee>(
            "Rahul",
            "103",
            600000.0f,
            std::make_shared<Department>(
                "10003",
                600
            ),
            "Proj",
            "Banglore",
            Grade::A,
            55
        )
    );
}

//Function To Display Objects
void DisplayObjects(Container& data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& emp:data){
        std::cout<<*emp<<std::endl;
    }
}

//Function to Display Bonus of Each Employee
void InvokeCalculateBonus(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& emp:data){
        std::cout<<emp->CalculateBonus()<<std::endl;
    }
}

//Function to Display Employee with Lowest Salary
void LowestSalaryEmployee(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    Pointer lowest = data.front();

    for(const auto& emp:data){
        if(emp->salary()<lowest->salary()){
            lowest=emp;
        }
    }
    std::cout<<*lowest<<std::endl;
    
}

//Function to Display Locations of Given Grade Employees
void EmployeeLocationFromGrade(Container & data, Grade grade){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    std::list<std::string> locations;
    for(const auto& emp:data){
        if(emp->grade()==grade){
            locations.emplace_back(emp->employeeLocation());
        }
    }

    for(const auto& loca:locations){
        std::cout<<loca<<std::endl;
    }
}

//Function to Return Project Name of Given Employee
std::string ProjectNameFromID(Container & data, std::string id){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& emp:data){
        if(emp->id()==id){
            return emp->projectName();
        }
    }

    throw std::runtime_error("Employee Not Found!!");
}