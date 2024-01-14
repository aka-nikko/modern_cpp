#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>

class Engine{
    private:
        std::string _id;

    public:
        //Default Constructor
        Engine()=delete;

        //Parameterized Constructor
        Engine(std::string id):_id(id){}

        //Copy Constructor
        Engine(const Engine&)=delete;

        //Copy Assignment Operator
        Engine& operator=(const Engine&)=delete;

        //Move Constructor
        Engine(Engine&&)=delete;

        //Move Assignment Operator
        Engine& operator=(Engine&&)=delete;

        //Destructor
        ~Engine()=default;

        //Getter Functions
        std::string id() const { return _id; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
            os << "_id: " << rhs._id;
            return os;
        }
};

#endif // ENGINE_H
