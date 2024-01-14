#include<iostream>

int Magic(int n1){
    std::cout<<"Address of n1 in Magic : "<<&n1<<"\n";
    int ans=n1*100;
    return ans;
}

int main(){
    //Data variable initialized with value 20
    int data=20;

    //Address of data can be determined because data is lvalue
    std::cout<<"Address of n1 in Main: "<<&data<<"\n";

    //Result stored the return value from magic called 
    //with "data" passed by value.
    int result=Magic(data);
    return 0;
}

/*
    Main            Magic            Heap
    <4bytes>        <4bytes>
    | 20 |- - - - > | 20 |
     data             n1

    <4bytes>        <4bytes>
    |2000|< - - - - |2000|
    result           ans

    When function goes out of scope-
    Main            Magic            Heap
    <4bytes>        <4bytes>
    | 20 |
     data 

    <4bytes>        <4bytes>
    |2000|
    result

    call by value means the data will be copied.
    copying stack to stack is fast. Heap to heap is slow.
*/