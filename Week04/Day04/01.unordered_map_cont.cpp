#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<memory>
#include<numeric>
#include"Timer.h"

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

    data.emplace(
        std::make_pair(104, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(105, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(106, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(107, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(108, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(109, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(110, std::make_shared<Employee>("Rahul",56000.0f))
    );

    data.emplace(
        std::make_pair(111, std::make_shared<Employee>("Rahul",56000.0f))
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

void CheckConditionAtLeastOne(const Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Check If Any Employee Has Salary More than 80000: ";
    std::cout<<std::boolalpha<<std::any_of(
        data.begin(),
        data.end(),
        [](const std::pair<int, Pointer>& ptr){
            return ptr.second->salary()>80000.0f;
        }
    )<<std::endl;
}

//Count Number of Map Pairs where Salary is above 50000
void CountAbove50000Employees(const Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Count Employee Who Have Salary More than 50000: ";
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [](const std::pair<int, Pointer>& ptr){
            return ptr.second->salary()>50000.0f;
        }
    )<<std::endl;
}

/*
    print the count of employees whose name is less then 7 characters
*/
void CountLessThan7CharNameEmployees(const Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Count Employee Who Have Name Less Than 7 Characters: ";
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [](const std::pair<int, Pointer>& ptr){
            return ptr.second->name().size()<7;
        }
    )<<std::endl;
}

/*
    find the salary for the employee ID is received as parameter (find_if)
*/
void FindEmployeeWithID(const Container& data, int id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    std::cout<<"Employee with Given ID: ";
    
    //Better Approach
    auto itr = data.find(id);

    //Using find_if on map is not good as it increases complexity.
    // auto itr = std::find_if(
    //     data.begin(),
    //     data.end(),
    //     [&](const std::pair<int, Pointer>& ptr){
    //         return ptr.first==id;
    //     }
    // );

    if(itr == data.end() ){
        std::cout << "Such Employee does not exist\n";
    }else{
        int pos = std::distance(data.begin(),itr);
        std::cout<< "Element Position: "<<pos<< " Element: "<<itr->second->salary()<<"\n";
    }
}

/*
    find average salary of only those employees whose id is passed as a vector of integers to the function 
*/
void AverageSalaryOfGivenIDs(const Container& data, std::vector<int> IDs){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    int count=0;
    float total_val=0.0f;

    for(int& id : IDs){
        total_val=std::accumulate(
            data.begin(),
            data.end(),
            0.0f,
            [&](float sum_till_current_val, const std::pair<int,Pointer>& row){
                if(row.first==id){
                    count++;
                    return sum_till_current_val+row.second->salary();
                }
                return sum_till_current_val;
            }
        );
    }
    std::cout<<"Average Salary: "<<total_val/count<<std::endl;
}

//Using find_if algo for the same is not good since it increases the time complexity.
void AverageSalaryOfGivenIDs0(const Container& data, std::vector<int> IDs){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float total_val=0.0f;
    int count=0;

    for(int& id : IDs){
        auto itr=std::find_if(
            data.begin(),
            data.end(),
            [&](const std::pair<int, Pointer>& ptr){
                return id==ptr.first;
            }
        );
        if(itr != data.end() ){
            count++;
            total_val=total_val+itr->second->salary();
        }
    }
    std::cout<<"Average Salary: "<<total_val/count<<std::endl;
}

//Improved->
void AverageSalaryOfGivenIDsImproved(const Container& data, std::vector<int> IDs){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float total_val=0.0f;
    int count=0;

    for(int& id : IDs){
        auto itr = data.find(id);

        if(itr != data.end() ){
            count++;
            total_val=total_val+itr->second->salary();
        }
    }
    std::cout<<"Average Salary: "<<total_val/count<<std::endl;
}

int main(){
    Container mydata;
    CreateObjects(mydata);

    for(auto& emp : mydata){
        std::cout<<"ID: "<<emp.first<<" "<<*emp.second<<std::endl;
    }

    TotalSalary(mydata);
    std::cout<<"Min Salary Employee Name: "<<FindMinSalaryEmployeeName(mydata)<<std::endl;

    CheckConditionAtLeastOne(mydata);

    CountAbove50000Employees(mydata);

    CountLessThan7CharNameEmployees(mydata);

    FindEmployeeWithID(mydata, 101);

    std::vector<int> IDs{101, 103, 106};

    {
        Timer time;
        AverageSalaryOfGivenIDs(mydata, IDs);
    }

    {
        Timer time;
        AverageSalaryOfGivenIDs0(mydata, IDs);
    }

    {
        Timer time;
        AverageSalaryOfGivenIDsImproved(mydata, IDs);
    }
    
    return 0;
}

/*
    01. copy: 
    copy all elements gets copied from source to destination unconditionally
    
    02. copy_if:
    copy all elements gets copied from source to destination if the elements satidfy the condition

    03. all_of:
    return a boolean to indicate if all elements satisfy condition

    04. any_of:
    return a boolean to indicate if at least one element satisfy condition

    05. none_of:
    return a boolean to indicate if none of the elements satisfy condition.

    06. count_if:
    return count of elements that satisfy condition.

    07. find_if:
    return the iterator to the first element that satisfy the condition, else end iterator (when no element satisfy condition).

    08. accumulate:
    produces one aggregated final output value by performing binary operations.

    09. max_element:
    returns iterator to the "maximum" element in the container.
    Maximum can be determined by writing a custom comparator

    10. min_element:
    returns iterator to the "minimum" element in the container.
    Minimum can be determined by writing a custom comparator

    11. sort:
    Write a comarator to perform ascending or decending sort of original container (in-place sorting).

    

*/