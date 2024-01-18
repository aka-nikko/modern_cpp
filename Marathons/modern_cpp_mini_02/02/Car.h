#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car{
    private:
        std::string _manufacturer;
        std::string _model;
        int _saleUnit;
        float _resaleValue;
        float _price;
        int _horsePower;

    public:
        //Default Constructor
        Car()=delete;

        //Parameterized Constructor
        Car(std::string manufacturer, std::string model, int saleUnit, 
            float resaleValue, float price, int horsePower);

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

        //Getter Functions
        std::string manufacturer() const { return _manufacturer; }
        std::string model() const { return _model; }
        int saleUnit() const { return _saleUnit; }
        float resaleValue() const { return _resaleValue; }
        float price() const { return _price; }
        int horsePower() const { return _horsePower; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
