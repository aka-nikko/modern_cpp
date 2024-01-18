#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include"ProductType.h"
#include"ProductOrigin.h"

class Product{
    private:
        std::string _productId;
        ProductType _productType;
        float _productPrice;
        std::string _productBrand;
        ProductOrigin _productOrigin;
        float _productTaxamount;

    public:
        //Default Constructor
        Product()=delete;

        //Parameterized Constructor
        Product(std::string id, ProductType type, float price, 
                std::string brand, ProductOrigin origin, 
                float taxamount);

        //Copy Constructor
        Product(const Product&)=delete;

        //Copy Assignment Operator
        Product& operator=(const Product&)=delete;

        //Move Constructor
        Product(Product&&)=delete;

        //Move Assignment Operator
        Product& operator=(Product&&)=delete;

        //Destructor
        ~Product()=default;

        //Getter Functions
        std::string productId() const { return _productId; }
        ProductType productType() const { return _productType; }
        float productPrice() const { return _productPrice; }
        std::string productBrand() const { return _productBrand; }
        ProductOrigin productOrigin() const { return _productOrigin; }
        float productTaxamount() const { return _productTaxamount; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
};

#endif // PRODUCT_H
