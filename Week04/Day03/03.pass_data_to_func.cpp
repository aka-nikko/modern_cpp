#include<iostream>

/*
    Pass by value: accept both lvalue and rvalye.
    rvalue is assigned
    lvalue is copied.
    n1 is also modifyable in the scope of f1
*/
void f1(int n1){
    std::cout<<"Address of n1 in f1 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f1 before Modification: "<<n1<<std::endl;
    n1=100;
    std::cout<<"Value of n1 in f1 after Modification: "<<n1<<std::endl;
}

/*
    Pass by non-const reference: accept only lvalue. rvalye cannot be passed.
    No copy created.
    Original value is accessed by reference
*/
void f2(int& n1){
    std::cout<<"Address of n1 in f2 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f2 before Modification: "<<n1<<std::endl;
    n1=100;
    std::cout<<"Value of n1 in f2 after Modification: "<<n1<<std::endl;
}

/*
    Pass by const valuw: accept both lvalue and rvalye  but does not allow any modification.
    lvalue is copied.
    rvalue is assigned
*/
void f3(const int n1){
    std::cout<<"Address of n1 in f3 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f3 before Modification: "<<n1<<std::endl;
    // n1=100; //Gives Error: canot modify const value
    std::cout<<"Value of n1 in f3 after Modification: "<<n1<<std::endl;
}

/*
    Accepts both lvalue and rvalue. 
    lvalue will be taken by reference.
    ravlue will be assigned to n1.
    No modfication.
*/
void f4(const int& n1){
    std::cout<<"Address of n1 in f4 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f4 before Modification: "<<n1<<std::endl;
    // n1=100;
    std::cout<<"Value of n1 in f4 after Modification: "<<n1<<std::endl;
}

/*
    only accepts rvalues.
    rvalues maps itself to n1.
    n1 can also be modified inside f5
*/
void f5(int&& n1){
    std::cout<<"Address of n1 in f5 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f5 before Modification: "<<n1<<std::endl;
    n1=100;
    std::cout<<"Value of n1 in f5 after Modification: "<<n1<<std::endl;
}

/*
    
*/
void f6(const int&& n1){
    std::cout<<"Address of n1 in f6 Function: "<<&n1<<std::endl;
    std::cout<<"Value of n1 in f6 before Modification: "<<n1<<std::endl;
    // n1=100;
    std::cout<<"Value of n1 in f6 after Modification: "<<n1<<std::endl;
}

int main(){
    int n1=10;
    f1(n1);
    f2(n1);
    return 0;
}