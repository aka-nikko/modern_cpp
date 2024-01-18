#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include"OrderType.h"

class Order{
private:
    std::string _id;
    float _value;
    OrderType _type;
    float _discount;

public:
    //Default Constructor
    Order()=delete;

    //Parameterized Constructor
    Order(std::string id, float value, OrderType type, float discount);

    //Copy Constructor
    Order(const Order&)=delete;

    //Copy Assignment Operator
    Order& operator=(const Order&)=delete;

    //Move Constructor
    Order(const Order&&)=delete;

    //Move Assignment Operator
    Order& operator=(const Order&&)=delete;

    //Default Destructor
    ~Order()=default;

    //Getter and Setter Functions
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float value() const { return _value; }
    void setValue(float value) { _value = value; }

    OrderType type() const { return _type; }
    void setType(const OrderType &type) { _type = type; }

    float discount() const { return _discount; }
    void setDiscount(float discount) { _discount = discount; }

    //Insertions Operator (<<) Overloaded
    friend std::ostream &operator<<(std::ostream &os, const Order &rhs);
};



#endif // ORDER_H
