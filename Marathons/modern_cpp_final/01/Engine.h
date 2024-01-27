#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include"EngineType.h"

class Engine{
    private:
        std::string _id;
        size_t _horsePower;
        EngineType _engineType;
        float _engineCapacity;
        float _engineTorque;

    public:
        //Default Constructor
        Engine()=delete;

        //Parameterized Constructor
        Engine(std::string id, size_t horsePower, EngineType engineType, 
                float engineCapacity, float engineTorque);

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
        EngineType engineType() const { return _engineType; }
        float engineCapacity() const { return _engineCapacity; }
        float engineTorque() const { return _engineTorque; }
        size_t horsePower() const { return _horsePower; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
