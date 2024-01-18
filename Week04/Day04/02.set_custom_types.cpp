#include<iostream>
#include<set>
#include<functional>

struct Employee{
    int _id;
    float _salary;

    Employee(int id, float _salary):
        _id(id), _salary(_salary){}

    bool operator<(const Employee& rhs) const {
        return (_salary<rhs._salary);// || (_salary>rhs._salary) || (_salary!=rhs._salary);
    }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id
           << " _salary: " << rhs._salary;
        return os;
    }
};

template<typename T>
void Display(std::set<T>& container){
    for(const T& emp : container){
        std::cout<<emp<<std::endl;
    }
}

int main(){
    Employee e1(101, 89000.0f), e2(102, 78000), e3(103, 80000.0f);
    std::set<Employee> s1{e1, e2, e3};
    
    Display(s1);
    return 0;
}

/*
    Comparator: How many conditions?
    Ans: Comparator must be designed for strict weak ordering which requires equivalence check

    I have smart pointers and i want to store them in set
    Write a comparison function for smart_poiinter<T> as a global function (can use functors in many cases)

    What about marathon
    Ans. Final marathon may include questions on set of primitive types of user-defined custom classes but NOT USING SMART POINTER.
*/