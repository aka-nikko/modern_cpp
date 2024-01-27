#ifndef DEVELOPER_H
#define DEVELOPER_H

#include<iostream>
#include"SkillSet.h"

class Developer{
    private:
        std::string _name;
        float _salary;
        int _experience_years;
        SkillSet _skill;

    public:
        //Default Constructor
        Developer()=delete;

        //Parameterized Constructor
        Developer(std::string name, float salary, int experience_years, SkillSet skill);

        //Copy Constructor
        Developer(const Developer&)=delete;

        //Copy Assignment Operator
        Developer& operator=(const Developer&)=delete;

        //Move Constructor
        Developer(Developer&&)=delete;

        //Move Assignment Operator
        Developer& operator=(Developer&&)=delete;

        //Destructor
        ~Developer()=default;

        //Function to Calculate Bonus
        float CalculateBonus();

        //Getter Functions
        std::string name() const { return _name; }
        float salary() const { return _salary; }
        int experienceYears() const { return _experience_years; }
        SkillSet skill() const { return _skill; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);
};

#endif // DEVELOPER_H
