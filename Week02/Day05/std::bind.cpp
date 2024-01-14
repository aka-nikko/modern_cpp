#include<iostream>
#include<functional>

void formula(int x, int y, int z){
    std::cout<<((x+y)-z)<<std::endl;
}

struct Actor{
    void DoSomethingYouUselessPerson(int x, int y, int z){
        std::cout<<((x+y)-z)<<std::endl;
    }
};

void demo(int x, int& y){
    x++; //x has been copied into demo
    y++; //we are using original data passed in 2nd position
}

using namespace std::placeholders;

int main(){
    //partial implementation of formula where x is set to 100 already
    auto partial_formula_f1=std::bind(&formula, 100, _2, _3); //x=100
    partial_formula_f1(-1, 29, 45); //-1 is discarded, 29 is _2(y), 45 is _3(z)

    auto partial_formula_f2=std::bind(&formula, 100, _1, _2); //x=100
    partial_formula_f2(50, 45); //x=100 (already), 50 is _1(y), 45 is _2(z)
    partial_formula_f2(50,45,50,100,200,400,40,50); //x=100 (already), 50 is _1(y), 45 is _2(z)

    auto partial_formula_f3=std::bind(&formula, _1, 100, _3); //y=100
    partial_formula_f3(90, -1, 80); //y=100 (already), 90 is _1(x), 80 is _3(z)
                                    //formula (90, 100, 80)
    /*
        Rules: formula has 3 parameters
                _1 means x is left for user to decide
                    : pick 1st value for x
                100 means y is fixed to 100
                _3 means z is left for user to decide
                    : pick 3rd value for z
    */

    auto partial_function_swap = std::bind(&formula, _3, _2, _1);
     /*
        rules : formula has 3 parameters

        _3 means x is decided by the user
            : pick the 3rd parameter and map to x

        _2 means y is decided by the user
            : pick the 2nd parameter and map to y

        _1 means z is decided by the user
            : pick the 1st parameter and map it to z
    */

    /*
    name of node, duration, trafic state (category)
    Birmingham street, 10, MODERATE
    getCordinates() : traffic category, duration, name of node
    bind(_3, _2, _1)
   */
   Actor a1;
   auto class_func_bind=std::bind(&Actor::DoSomethingYouUselessPerson, &a1, _3, _2, _1);
   class_func_bind(-1, 50, 45);
}

/*
    bind does the following
    a) fixes the value of one or more parameters of a function it partially
    implements by using concept of placeholders and dedicated values
    b) It can be used to switch the order of values passed by mapping
    them in any sequence programmer desires
*/