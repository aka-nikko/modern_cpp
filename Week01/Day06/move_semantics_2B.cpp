/*
    Creating a function Magic.
    It needs to accept one integer "data"

    Scenario 01:
        Copy and Create duplicated data value to preserve original
        value inside data and yet perform operations on the copy
        inside magic
        - Pass By Value

    Scenario 02: 
        I have "temporary" integer which needs to be passed to magic.
        Magic would perform operations like modification on the integer
        and return the modified value.
        A. Pass Integer rvalue reference and return modified data by value
        B. pass integer by value and return by value

*/


/*
    Scenario 02.B
*/
#include"Employee.h"
#include<memory>

int Magic(int data){}

Employee Magic(Employee data){}

std::shared_ptr<Employee> Magic(std::shared_ptr<Employee> data){}

int main(){
    Magic(10);
    int n1=20;
    Magic(n1);

    Magic(Employee(100));
    Employee e1(100);
    Magic(e1); //e1 passed by value

    Magic(std::make_shared<Employee>(100));
    std::shared_ptr<Employee> ptr = std::make_shared<Employee>(100);
    Magic(ptr);

    return 0;
}