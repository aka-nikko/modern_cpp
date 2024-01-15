#include"Functionalities.h"

using namespace std::placeholders;

int main(){
    Container data;
    data.emplace_back(std::make_shared<Employee>(
        101,
        "Nikko",
        1000000.0f
    ));
    std::cout<<AverageSalary(data)<<std::endl;
    //SalaryGivenId(data, 101);
    // auto fn = std::bind(SalaryGivenId, _1, 101);
    // fn(data); //101 should be hard coded (fixed)

    return 0;
}