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
    for(const FnType & fn : functions){
        for(const int n : data){
            fn(n);
        }
    }
}

int main(){
    FnContainer functions;
    MakeLamdaFunctions(functions);
    DataContainer data{10,20,30};
    ApplyLogicOnData(functions,data);

    return 0;
}