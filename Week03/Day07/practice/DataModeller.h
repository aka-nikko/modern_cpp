#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include<iostream>
#include<variant>
#include<memory>
#include<vector>
#include"Employee.h"
#include"BusinessOwner.h"

using EmpPointer=std::unique_ptr<Employee>;
using BusinessPointer=std::unique_ptr<BusinessOwner>;
using Vtype=std::variant<BusinessPointer,EmpPointer>;

class DataModeller{
    private:
        Vtype _instance;
        std::vector<float> _goodsPrices;

    public:
        //Default Constructor
        DataModeller()=delete;

        //Parameterized Constructor
        DataModeller(Vtype instance, const std::vector<float>& goodsPrices);

        //Copy Constructor
        DataModeller(const DataModeller&)=delete;

        //Copy Assignment Operator
        DataModeller& operator=(const DataModeller&)=delete;

        //Move Constructor
        DataModeller(DataModeller&&)=delete;

        //Move Assignment Operator
        DataModeller& operator=(DataModeller&&)=delete;

        //Destructor
        ~DataModeller()=default;

        //()Operator Overload
        void operator()();

        //Getter Functions
        const Vtype& instance() const { return _instance; }
        std::vector<float> goodsPrices() const { return _goodsPrices; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const DataModeller &rhs);
};

#endif // DATAMODELLER_H
