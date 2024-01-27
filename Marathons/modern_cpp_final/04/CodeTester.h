#ifndef CODETESTER_H
#define CODETESTER_H

#include<iostream>
#include"SkillSet.h"

class CodeTester{
    private:
        std::string _name;
        float _salary;
        int _experience_years;
        SkillSet _skill;

    public:
        //Default Constructor
        CodeTester()=delete;

        //Parameterized Constructor
        CodeTester(std::string name, float salary, int experience_years, SkillSet skill);

        //Copy Constructor
        CodeTester(const CodeTester&)=delete;

        //Copy Assignment Operator
        CodeTester& operator=(const CodeTester&)=delete;

        //Move Constructor
        CodeTester(CodeTester&&)=delete;

        //Move Assignment Operator
        CodeTester& operator=(CodeTester&&)=delete;

        //Destructor
        ~CodeTester()=default;

        //Function to Calculaye Bonus
        float CalculateBonus();

        //Getter Functions
        std::string name() const { return _name; }
        float salary() const { return _salary; }
        int experienceYears() const { return _experience_years; }
        SkillSet skill() const { return _skill; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const CodeTester &rhs);
};

#endif // CODETESTER_H
