/*
    A container of 3 functions
    Then run a loop over the container to execute the functions

       DATA
    |   |   |
    f1  f2  f3
    |   |   |
    o1  o2  o3
*/

#include<iostream>
#include<functional>
#include<vector>

using FnType=std::function<void(int)>;
using FnContainer=std::vector<FnType>;

/*
    Accept blank container
    It will add 3 lamdas into the container
*/
void MakeLamdaFunctions(FnContainer& functions){
    functions.emplace_back(
        [](int number){std::cout<<number*number<<std::endl;}
    );

    functions.emplace_back(
        [](int number){std::cout<<number*number*number<<std::endl;}
    );
    
}

/*
    Run a for each loop on the function container
    execute each funtion with given data
*/
void ApplyLogicOnData(FnContainer& functions, int data){
    for(FnType & fn : functions){
        fn(data);
    }
}

int main(){
    FnContainer functions;
    MakeLamdaFunctions(functions);
    ApplyLogicOnData(functions, 5);
    return 0;
}