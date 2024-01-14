#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include<memory>
#include<functional>
#include"EngineType.h"

class Engine{
    private:
        int _horsepower;
        EngineType _engineType;
        
    public:
        //Default Constructor
        Engine()=delete;

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

        //Parameterized Constructor
        Engine(int horsepower, EngineType type);

        //Getter Functions
        int horsepower() const { return _horsepower; }
        EngineType engineType() const { return _engineType; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};


#endif // ENGINE_H
