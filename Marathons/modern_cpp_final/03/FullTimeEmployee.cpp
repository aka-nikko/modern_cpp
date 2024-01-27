#include"FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(std::string name, std::string id, float salary, 
        std::string project_name, std::string employee_location, 
        Grade grade, int bonus_percent):
    Employee(name, id, salary), _project_name(project_name), 
    _employee_location(employee_location), _grade(grade), _bonus_percent(bonus_percent) {}

float FullTimeEmployee::CalculateBonus(){
    float value=0.0f;
    if(_grade==Grade::A){
        value = _bonus_percent*Employee::salary();
    }else if(_grade==Grade::B){
        value = _bonus_percent*(Employee::salary()/2);
    }else{
        value = _bonus_percent*(Employee::salary()/4);
    }
    return value;
}

std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs) {
    os << "_project_name: " << rhs._project_name
       << " _employee_location: " << rhs._employee_location
       << " _grade: " << static_cast<int>(rhs._grade)
       << " _bonus_percent: " << rhs._bonus_percent;
    return os;
}
