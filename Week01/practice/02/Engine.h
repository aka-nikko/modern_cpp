#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include"EngineType.h"

class Engine{
    private:
        std::string engineNumber;
        EngineType engineType;
        int engineHorsepower;
        int engineTorque;

    public:
        Engine()=default;

        Engine(const Engine&)=default;
        Engine& operator=(const Engine&)=default;

        Engine(Engine&&)=default;
        Engine& operator=(Engine&&)=delete;

        Engine(std::string number, EngineType type, int horsepower, int torque);

        ~Engine()=default;

        std::string getEngineNumber() const { return engineNumber; }
        void setEngineNumber(const std::string &engineNumber_) { engineNumber = engineNumber_; }

        EngineType getEngineType() const { return engineType; }
        void setEngineType(const EngineType &engineType_) { engineType = engineType_; }

        int getEngineHorsepower() const { return engineHorsepower; }
        void setEngineHorsepower(int engineHorsepower_) { engineHorsepower = engineHorsepower_; }

        int getEngineTorque() const { return engineTorque; }
        void setEngineTorque(int engineTorque_) { engineTorque = engineTorque_; }

        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};


#endif // ENGINE_H
