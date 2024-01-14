#include<iostream>
#include<functional>
#include<array>

auto n1=10;

using FnType=std::function<int(int)>;

/*
    WHAT?
    Lamdas are callables like regular functions (top-level functions/Global functions)
    Lamdas have no names i.e they are anonymous functions.

    WHY?
    They help us to pass, reveive, store and utilize logic in the
    form of an object with proper type system support.

    They can be used for specifying short-term, one time or scope 
    based logical process to be performed on some data

    CPP lamdas have a concept of capture clause which allows them
    to act like closures.
*/

/*
    a). [n1] : Capture n1 by value
    b). [=]  : Capture and use all variables from surrounding function by value
    Options and b will not allow

    [&n1]: Capture n1 by lvalue reference
    [&]  : Capture and use all variables from surrounding function by reference.
*/

void operation(std::function<void()>f){
        f();
}

int main(){
    auto lfn1=[](int number){return number*number;};
    std::array<FnType,1>arr{lfn1};
    int n1=100;
    std::cout<<lfn1(n1)<<std::endl;

    //Capture n1 by reference
    auto lf1=[&n1](){std::cout<<n1*n1<<std::endl;};
    lf1();

    //Add mutable keyword to make value mutable
    auto lf2=[n1]() mutable {n1=10;std::cout<<n1*n1<<std::endl;};

    /*
        lamdas to be used as "Closures"
        (also known as lamda closures)
    */
    auto lf3=[n1](){int data=10; std::cout<<n1*data<<std::endl;};
    operation(lf3);
    return 0;
}