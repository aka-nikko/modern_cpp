#ifndef DEBITCARD_H
#define DEBITCARD_H

#include<iostream>
#include"DebitCardType.h"

class DebitCard final{
    private:
        int _cvv{0};
        std::string _name_on_card{""};
        std::string _expiry{""};
        DebitCardType _type{DebitCardType::DOMESTIC};

    public:
        //Default Constructor
        DebitCard()=delete;

        //Copy Constructor
        DebitCard(const DebitCard&)=delete;

        //Copy Assignment
        DebitCard& operator=(const DebitCard&)=delete;

        //Move Constructor
        DebitCard(DebitCard&&)=delete;

        //Move Assignment
        DebitCard& operator=(DebitCard&&)=delete;

        //Destructor
        ~DebitCard()=default;

        //Parameterized Constructor
        DebitCard(int cvv, std::string dname, std::string expiry, DebitCardType dtype);

        //Getter Functions
        int cvv() const { return _cvv; }
        std::string name() const { return _name_on_card; }
        std::string expiry() const { return _expiry; }
        DebitCardType type() const { return _type; }

        //Insertion Operator Overloaded
        friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
