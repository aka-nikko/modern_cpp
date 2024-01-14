#include"Functionalities.h"

std::function<float (Container&)> AverageSalary=[](Container& data){
    float total=0.0f;

    for(Pointer& ptr:data){
        total+=ptr->salary();
    }
    return total;
};