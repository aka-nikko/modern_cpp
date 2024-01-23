#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"CarChassis.h"

class Car{
    private:
        int _seat_count;
        float _price;
        CarChassis _chasis;

    public:
        //Default Constructor
        Car()=delete;

        //Parameterized Constructor
        Car(int seat_count, float price, CarChassis chasis);

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

        int seatCount() const { return _seat_count; }

        float price() const { return _price; }

        CarChassis chasis() const { return _chasis; }

        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

        //Getter Functions

        //Stream Output Operator
};

#endif // CAR_H
