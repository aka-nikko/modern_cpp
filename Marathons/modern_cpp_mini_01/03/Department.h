#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<iostream>

class Department{
private:
    std::string _id;
    int _size;

public:
    //Default Constructor
    Department()=delete;

    //Parameterized Constructor
    Department(std::string id, int size);

    //Copy Constructor
    Department(const Department&)=delete;

    //Copy Assignment Operator
    Department& operator=(const Department&)=delete;

    //Move Constructor
    Department(const Department&&)=delete;

    //Move Assignment Operator
    Department& operator=(const Department&&)=delete;

    //Default Destructor
    ~Department()=default;

    //Getter and Setter Functions
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    int size() const { return _size; }
    void setSize(int size) { _size = size; }

    friend std::ostream &operator<<(std::ostream &os, const Department &rhs);
};


#endif // DEPARTMENT_H
