#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <ostream>

class Employee{
    private:
        int _id;
        float _salary;

    public:
        Employee() = default;
    
        Employee(const Employee& ) = default;
    
        Employee& operator=(const Employee&) = default;
    
        Employee(Employee&&) = default;
    
        Employee& operator=(Employee&& ) = default;
        
        float CalculateTax();
        
        Employee(int id, float salary);

        ~Employee() = default;

        int id() const { return _id; }

        float salary() const { return _salary; }

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
