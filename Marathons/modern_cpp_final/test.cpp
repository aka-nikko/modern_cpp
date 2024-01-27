#include <list>
#include <iostream>
#include <algorithm>

/*
    elements get copied at the front of the list if condition is met
*/
int main(){
    std::list<int> data {1, 2, 3, 4, 5};
    std::list<int> result;

    std::copy_if(data.begin(), data.end(), result.begin(), [](int val){return val % 2 == 0;});

    std::cout << result.front();
}

#include<iostream>

class test{
    private:
        

    public:
        //Default Constructor
        test()=delete;

        //Parameterized Constructor
        test(/*parameters*/);

        //Copy Constructor
        test(const test&)=delete;

        //Copy Assignment Operator
        test& operator=(const test&)=delete;

        //Move Constructor
        test(test&&)=delete;

        //Move Assignment Operator
        test& operator=(test&&)=delete;

        //Destructor
        ~test()=default;

        //Getter Functions

        //Stream Output Operator
};