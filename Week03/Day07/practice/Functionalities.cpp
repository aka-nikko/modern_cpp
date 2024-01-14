#include"Functionalities.h"
#include"DataModeller.h"
#include<mutex>

std::mutex mt;

void CreateObjects(Container& data){
    data.emplace_back(
        std::make_unique<DataModeller>(
            //Instance
            std::make_unique<Employee>(
                "Nikko",
                EmployeeType::REGULAR,
                500000.0f
            ),
            //Vector of floats
            std::vector<float>{12.0f,43.0f,43.0f}
        )
    ); 

    data.emplace_back(
        std::make_unique<DataModeller>(
            //Instance
            std::make_unique<BusinessOwner>(
                1000000.0f,
                2000000.0f,
                "XYZ Corporation",
                BusinessType::MNC
            ),
            //Vector of floats
            std::vector<float>{12.0f,65.0f,34.0f}
        )
    ); 
}

/*
    This function will accept a Container or DataModeller pointer

    FOR EACH POINTER, perform following-
    1. Capture the instance reference
    2. Use holds_alternative to verify which type of pointer is present in the _instance
    3. If pointer is of type BusinessOwner
        a. use std::get to fetch BusinessOwnerPointer (This will be safe)
        b. use the fetched pointer in BusinessOwner to calculate tax for business

    else if pointer of of type Employee
        a. use std::get to fetch EmployeePointer
        b. use the fetched pointer to fetch type of employee
        c. if type is REGULAR tax is 10%, else it should be 20% of salary
*/

void CalculateTaxPayable(const Container & data){
    for(const DataVariant& ptr : data){
        const Vtype& val = ptr->instance();
        if(std::holds_alternative<BusinessPointer>(val)){
            const BusinessPointer& p =std::get<BusinessPointer>(val);
            mt.lock();
            std::cout<<"Business Owner Tax: "<<0.1f*(p->revenue()-p->expenseAmount())<<std::endl;
            mt.unlock();
        }else{
            //If initializaion
            if(const EmpPointer& p = std::get<EmpPointer>(val); p->type()==EmployeeType::REGULAR){
                std::lock_guard<std::mutex> lk(mt);
                std::cout<<"Employee Tax is 10%: "<<0.1f*p->salary()<<std::endl;
            }else{
                std::lock_guard<std::mutex> lk(mt);
                std::cout<<"Employee Tax is 20%: "<<0.2f*p->salary()<<std::endl;
            }
        }
    }
}

/*
    Call the parent operator overload
*/
void CallParenOperator(const Container & data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }else{
        for(const DataVariant& ptr : data){
            std::lock_guard<std::mutex> lk(mt);
            ptr->operator()();
        }
    }
}