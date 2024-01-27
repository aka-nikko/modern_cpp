#include"Functionalities.h"

int main(){
    Container mydata;
    CreateObjects(mydata);

    //Display All Data
    for(auto& emp : mydata){
        std::cout<<*emp<<std::endl;
    }


    //Display Bonus of All Employees
    std::cout<<"\nBonuses of All Employees:"<<std::endl;
    try{
        InvokeCalculateBonus(mydata);
    }catch(std::runtime_error& msg){
        std::cout<<msg.what()<<std::endl;
    }


    //Function to Display Employee Details with Maximum Salary
    try{
        DisplayEmployeeWithMaxSalary(mydata);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Display All Employee Locations of Given Grade
    try{
        std::promise<Grade> pr_grade;
        std::future<Grade> ft_grade = pr_grade.get_future();
        std::future<void> result__grade_grade = std::async(
                                        std::launch::async, 
                                        &AllEmployeeLocationsOfGivenGrade, 
                                        std::ref(mydata), 
                                        std::ref(ft_grade)
                                    );
        pr_grade.set_value(Grade::A);
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };


    //Function to Return Project name of Given Employee ID
    std::cout<<"Project Name of Given Employee ID: ";
    try{
        std::promise<std::string> pr_pname;
        std::future<std::string> ft_pname = pr_pname.get_future();
        std::future<std::string> result_ft_pname = std::async(
                                        std::launch::async, 
                                        &ProjectNameOfGivenID, 
                                        std::ref(mydata), 
                                        std::ref(ft_pname)
                                    );
        pr_pname.set_value("101");
        std::cout<<result_ft_pname.get()<<std::endl;
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };
    return 0;
}