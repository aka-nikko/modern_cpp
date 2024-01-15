#include"Functionalities.h"
#include<algorithm>
#include<numeric>

std::function<float (Container&)> AverageSalary=[](Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float result=std::accumulate(
        data.begin(),
        data.end(),
        0.0,
        [](float current_result, Pointer& p){
            return current_result+p->salary();
        }
    );
    return result/data.size();
};