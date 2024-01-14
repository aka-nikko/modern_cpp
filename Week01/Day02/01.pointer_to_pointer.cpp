#include<iostream>

/*
       &                       (just name)
    Address         Name        Content
    0x100H          n1          10
    0x111H          ptr         0x100H
    0x891H          sptr        0x111H
*/

int main(){
    int n1=10;
    int* ptr=&n1;

    //sptr is a pointer to a pointer
    int** sptr=&ptr;

    std::cout<<"Address of n1  : "<<&n1<<"\n";
    std::cout<<"Content of ptr : "<<ptr<<"\n";

    std::cout<<"Address of ptr : "<<&ptr<<"\n";
    std::cout<<"Content of sptr: "<<sptr<<"\n";

    std::cout<<*sptr<<"\n";
    std::cout<<**sptr<<"\n";
    
    return 0;
}