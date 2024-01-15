#include<unistd.h>
#include<iostream>

int main(){
    int id=fork();
    if(id==0){
        std::cout<<"This statement is Printed in the Child"<<std::endl;
        std::cout<<"Process ID: "<<getpid()<<"\nParent  ID: "<<getppid()<<std::endl;
    }else{
        std::cout<<"This comes from Parent"<<std::endl;
        std::cout<<"Process ID: "<<getpid()<<"\nParent  ID: "<<getppid()<<std::endl;
    }
    return 0;
}