#include"Functionalities.h"

int main(){
    Container mydata;
    CreateObjects(mydata);

    //Display All Employee Data and Bonus
    for (const auto& [id, obj] : mydata) {
        std::cout<<"_id: "<<id;
        std::visit([](const auto& employee) {
            std::cout<<*employee<<"\n";
            std::cout<<"Bonus: "<<employee->CalculateBonus();
        }, obj);
        std::cout<<"\n";
    }

    //Function to find employees with experience below 6
    auto findEmployeesBelowSix = std::async(FindEmployeesWithExperienceBelowSix, mydata);

    //Function to calculate average salary of CodeTesters
    auto calculateAverageSalary = std::async(CalculateAverageSalaryOfCodeTesters, mydata);

    //Function to count employees with salary above 50000
    auto countAbove50K = std::async(CountEmployeesWithSalaryAbove50K, mydata);

    //Function to find and display the salary of an employee by _id
    auto findSalary = std::async(FindSalaryById, mydata, "101"); //Change the employeeId as needed

    //Function to check if all employees have salary above 60000
    auto allAbove60000 = std::async(AllSalariesAbove60000, mydata);

    //Wait for all asynchronous tasks to complete
    auto result = findEmployeesBelowSix.get();
    float averageSalary = calculateAverageSalary.get();
    int countAbove50KValue = countAbove50K.get();
    auto salary = findSalary.get();
    bool allAbove60000Value = allAbove60000.get();

    //Display results
    std::cout<<"\nEmployees with experience below 6:\n";
    for (const auto& [id, obj] : result) {
        std::cout<<"_id: "<<id;
        std::visit([](const auto& employee) {
            std::cout<<*employee<<"\n";
        }, obj);
    }

    std::cout<<"Average salary of CodeTesters: "<<averageSalary<<"\n";
    
    std::cout<<"Count of employees with salary above 50000: "<<countAbove50KValue<<"\n";

    if (salary.has_value()) {
        std::cout<<"Salary of employee with _id 101: "<<salary.value()<<"\n";
    } else {
        std::cout<<"Employee with _id 101 not found.\n";
    }

    if (allAbove60000Value) {
        std::cout<<"All employees have salary above 60000.\n";
    } else {
        std::cout<<"Not all employees have salary above 60000.\n";
    }
    return 0;
}