#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<memory>
#include"CustomerType.h"
#include"DebitCard.h"

class Customer{
    private:
        int _id{0};
        std::string _name{""};
        int _age{0};
        CustomerType _type{CustomerType::REGULAR};
        std::shared_ptr<DebitCard> _card;

    public:
        //Default Constructor
        Customer()=delete;

        //Copy Constructor
        Customer(const Customer&)=delete;

        //Copy Assignment Operator
        Customer& operator=(const Customer&)=delete;

        //Move Constructor
        Customer(Customer&&)=delete;

        //Move Assignment Operator
        Customer& operator=(Customer&&)=delete;

        //Destructor
        ~Customer()=default;

        //Parameterized Constructor
        Customer(int id, std::string name, int age, CustomerType type, 
                 std::shared_ptr<DebitCard> card);

        //Getter Functions
        int id() const { return _id; }
        std::string name() const { return _name; }
        int age() const { return _age; }
        CustomerType type() const { return _type; }
        std::shared_ptr<DebitCard> card() const { return _card; }

        //Insertion Operator Overloaded
        friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);        
};

#endif // CUSTOMER_H
