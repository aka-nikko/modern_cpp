#include"Employee.h"
#include"BusinessOwner.h"
#include<variant>
#include<memory>

int main(){
    std::variant<Employee, BusinessOwner> v1;

    v1=Employee();
    /*
        std::visit needs at least 2 parameters:
        First: Lamda function that explains what to do with item inside the variant
        Second (and subsequent): Objects of variant class. (object/s on which
        visit lamda has to be applied).
    */
    std::visit(
        [](auto&& val){val.PayTax();},
        v1
    );

    v1=BusinessOwner();
    std::visit(
        [](auto&& val){val.PayTax();},
        v1
    );

    std::shared_ptr<Employee> e1=std::make_shared<Employee>();
    std::variant<std::shared_ptr<Employee>, std::shared_ptr<BusinessOwner>> v2;

    v2=e1; //storing e1 inside varaint. This should be stored in slot 1

    std::visit(
        [](auto&& val){val->PayTax();},
        v2
    );
    
    
    std::get<BusinessOwner>(v1).PayTax();
    return 0;
}