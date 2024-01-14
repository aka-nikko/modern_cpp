/*
    A container of 3 functions
    Then run a loop over the container to execute the functions

    d1  d2  d3
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
using DataContainer=std::vector<int>;

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

    functions.emplace_back(
        [](int number){std::cout<<number*100<<std::endl;}
    );
}

/*
    Run a for each loop on the function container
    execute each funtion with given data
*/
void ApplyLogicOnData(const FnContainer& functions, const DataContainer& data){
    auto itr=data.begin();
    for(const FnType & fn : functions){
        int value=*itr++;
        fn(value);
    }
}

int main(){
    FnContainer functions;
    MakeLamdaFunctions(functions);
    DataContainer data{10,20,30};
    ApplyLogicOnData(functions,data);

    return 0;
}