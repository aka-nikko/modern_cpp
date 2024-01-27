#include"Developer.h"

Developer::Developer(std::string name, float salary, int experience_years, SkillSet skill):
    _name(name), _salary(salary), _experience_years(experience_years), _skill(skill) {}

float Developer::CalculateBonus(){
    float bonus=0.0f;
    if(_experience_years<5){
        bonus=0.1*_salary;
    }else if(_experience_years>=5){
        bonus=0.2*_salary;
    }
    return bonus;
}

std::ostream &operator<<(std::ostream &os, const Developer &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _experience_years: " << rhs._experience_years
       << " _skill: " << static_cast<int>(rhs._skill);
    return os;
}
