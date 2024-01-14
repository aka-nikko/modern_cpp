#include<iostream>
#include<memory>
#include"Employee.h"

using pointer=std::shared_ptr<Employee>;

pointer Magic(pointer emp){
    emp->setId(100);
    return emp;
}

int main(){
    pointer e1=std::make_shared<Employee>(111);
    pointer modified_e1=Magic(e1);
    return 0;
}