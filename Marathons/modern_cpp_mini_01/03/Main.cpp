#include"Functionalities.h"

int main(){
    Container mydata;

    CreateObjects(mydata);

    //Display All Employees
    std::cout<<"All Objects:"<<std::endl;
    DisplayObjects(mydata);

    //Display Bonus of All Employees
    std::cout<<"\nBonuses of All Employees:"<<std::endl;
    try{
        InvokeCalculateBonus(mydata);
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    //Display Employee with Lowest Salary
    std::cout<<"\nEmployee with Lowest Salary:"<<std::endl;
    try{
        LowestSalaryEmployee(mydata);
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }
    
    //Display Locations of Given Grade Employees
    std::cout<<"\nLocations of Grade A Employees:"<<std::endl;
    try{
        EmployeeLocationFromGrade(mydata, Grade::A);
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }

    //Project Name of Given Employee
    //Create a Container for Full Time Employees
    Container FullTimeEmployees;
    for(const auto& emp:mydata){
        FullTimeEmployees.emplace_back(emp);
    }
    
    std::cout<<"\nProject Name of Employee 101:"<<std::endl;
    try{
        std::string projectName = ProjectNameFromID(FullTimeEmployees, "101");
        std::cout<<projectName<<std::endl;
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }
    
    return 0;
}