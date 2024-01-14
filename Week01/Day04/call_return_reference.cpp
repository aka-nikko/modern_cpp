#include<iostream>

/*
    If there is a data type to the left of &,
    it indicates the reference of that data type.
*/

int& Magic(int& n1){
    std::cout<<"Address of n1 in Magic: "<<&n1<<"\n";
    n1=1;
    int ans=n1*100;
    return ans;
}

int main(){
    //Data variable initialized with value 20
    int data=20;

    //Address of data can be determined because data is lvalue
    std::cout<<"Address of n1 in Main : "<<&data<<"\n";

    //Result stored the return value from magic called 
    //with "data" passed by value.
    int result=Magic(data);
    return 0;
}

/*
    Reference means alias/alternate name

    Main            Magic            Heap
    0x100H          0x100H
    | 20 |          | 20 |
     data             n1

    |100| <- - - -  |100|
    result           ans

    When function goes out of scope-
    Main            Magic            Heap
    0x100H
    | 20 |
     data  

    dangling reference
    result
*/