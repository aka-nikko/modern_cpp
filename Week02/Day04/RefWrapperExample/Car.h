#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<memory>
#include<functional>
#include"Engine.h"

using Pointer = std::shared_ptr<Engine>;
using RefType = std::reference_wrapper<Pointer>;

class Car{
    private:
        int _id;
        std::string _model;
        float _price;
        RefType _engine;

    public:
        //Default Constructor
        Car()=delete;

        //Copy Constructor
        Car(const Car&)=delete;

        //Copy Assignment Operator
        Car& operator=(const Car&)=delete;

        //Move Constructor
        Car(Car&&)=delete;

        //Move Assignment Operator
        Car& operator=(Car&&)=delete;

        //Destructor
        ~Car()=default;

        //Parameterized Constructor
        Car(int id, std::string model, float price, RefType engine);

        //Getter Functions
        int id() const { return _id; }
        std::string model() const { return _model; }
        float price() const { return _price; }
        RefType engine() const { return _engine; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};


#endif // CAR_H
