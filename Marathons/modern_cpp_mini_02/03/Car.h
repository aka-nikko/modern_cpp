#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<functional>
#include<memory>
#include"Vehicle.h"
#include"Engine.h"
#include"CarCategory.h"

using EnginePointer=std::shared_ptr<Engine>;
using EngineRef=std::reference_wrapper<EnginePointer>;

class Car : public Vehicle{
    private:
        CarCategory _carCategory;
        EngineRef _engine;

    public:
        //Default Constructor
        Car()=delete;

        //Parameterized Constructor
        Car(std::string id, std::string manufacturer, float price, CarCategory carCategory, EngineRef engine);

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

        //Virtual Function
        float CalculateRegistrationCharges();

        //Getter Functions
        CarCategory carCategory() const { return _carCategory; }
        EngineRef engine() const { return _engine; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
