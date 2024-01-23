#ifndef BRAND_H
#define BRAND_H

#include<iostream>
#include<memory>
#include<array>
#include"BrandType.h"
#include"Car.h"

class Brand{
    private:
        BrandType _type;
        std::string _unique_tm;
        std::array<std::shared_ptr<Car>,3> _cars;

    public:
        //Default Constructor
        Brand()=delete;

        //Parameterized Constructor
        Brand(BrandType type, std::string unique_tm, std::array<std::shared_ptr<Car>,3> cars);

        //Copy Constructor
        Brand(const Brand&)=delete;

        //Copy Assignment Operator
        Brand& operator=(const Brand&)=delete;

        //Move Constructor
        Brand(Brand&&)=delete;

        //Move Assignment Operator
        Brand& operator=(Brand&&)=delete;

        //Destructor
        ~Brand()=default;

        BrandType type() const { return _type; }

        std::string uniqueTm() const { return _unique_tm; }

        std::array<std::shared_ptr<Car>,3> cars() const { return _cars; }

        friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);

        //Getter Functions

        //Stream Output Operator
};

#endif // BRAND_H
