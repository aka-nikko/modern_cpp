#ifndef OWNER_H
#define OWNER_H

#include<iostream>
#include"OwnerType.h"

class Owner{
    private:
        std::string _name;
        std::string _city;
        OwnerType _type;

    public:
        //Default Constructor
        Owner()=delete;

        //Parameterized Constructor
        Owner(std::string name, std::string city, OwnerType type);

        //Copy Constructor
        Owner(const Owner&)=delete;

        //Copy Assignment Operator
        Owner& operator=(const Owner&)=delete;

        //Move Constructor
        Owner(Owner&&)=delete;

        //Move Assignment Operator
        Owner& operator=(Owner&&)=delete;

        //Destructor
        ~Owner()=default;

        //Getter Functions
        std::string name() const { return _name; }
        std::string city() const { return _city; }
        OwnerType type() const { return _type; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Owner &rhs);
};

#endif // OWNER_H
