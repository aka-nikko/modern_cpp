#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<memory>
#include<numeric>

class Employee{
    private:
        std::string _name;
        float _salary;

    public:
        //Default Constructor
        Employee()=delete;

        //Parameterized Constructor
        Employee(std::string name, float salary):
            _name(name), _salary(salary) {}

        //Copy Constructor
        Employee(const Employee&)=delete;

        //Copy Assignment Operator
        Employee& operator=(const Employee&)=delete;

        //Move Constructor
        Employee(Employee&&)=delete;

        //Move Assignment Operator
        Employee& operator=(Employee&&)=delete;

        //Destructor
        ~Employee()=default;

        //Getter Functions
        std::string name() const { return _name; }
        float salary() const { return _salary; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
            os << "_name: " << rhs._name
               << " _salary: " << rhs._salary;
            return os;
        }
};

using Pointer = std::shared_ptr<Employee>;
using Container=std::unordered_map<int, Pointer>;

void CreateObjects(Container& data){
    data.emplace(
        std::make_pair(101, std::make_shared<Employee>("Nikko",70000.0f))
    );

    data.emplace(
        std::make_pair(102, std::make_shared<Employee>("Anshul",80000.0f))
    );

    data.emplace(
        std::make_pair(103, std::make_shared<Employee>("Rahul",56000.0f))
    );
}

//Total Salary for All Employees
void TotalSalary(const Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    // float total=0.0f;

    // for(auto& [k,v] : data){
    //     total=total+v->salary();
    // }

    //alternatevely
    // for(const auto& itr = data.begin();itr!=data.end();++itr){
    //     total=total+*itr->second->salary();
    // }

    //alternatively
    // for(const std::pair<int, Pointer>& ptr : data){
    //     total=total+ptr.second->salary();
    // }

    //alternatively
    float total_val=std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float sum_till_current_val, const std::pair<int,Pointer>& row){
            return sum_till_current_val+row.second->salary();
        }
    );

    std::cout<<"Total Salary: "<<total_val<<std::endl;
}

//Find Name of Employee with Lowest Salary
std::string FindMinSalaryEmployeeName(const Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<int, Pointer>& pair1, const std::pair<int, Pointer>& pair2) {
            return pair1.second->salary() < pair2.second->salary();
        }
    );

    return itr->second->name();
}

int main(){
    Container mydata;
    CreateObjects(mydata);

    for(auto& emp : mydata){
        std::cout<<"ID: "<<emp.first<<" "<<*emp.second<<std::endl;
    }

    TotalSalary(mydata);
    std::cout<<"Min Salary Employee Name: "<<FindMinSalaryEmployeeName(mydata)<<std::endl;
    return 0;
}