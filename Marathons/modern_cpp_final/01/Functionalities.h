#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Engine.h"
#include<memory>
#include<array>
#include<vector>
#include<algorithm>

using EnginePointer=std::shared_ptr<Engine>;
using EngineContainer=std::array<EnginePointer,3>;

//Function to Create 3 Instances of Engine
void CreateObjects(EngineContainer& data);

//Function to Return Container of EngineTypes Satisfying Given Condition
std::vector<EngineType> ReturnEngineTypesSatisfyingConditions(const EngineContainer& data);

//Function to Check if All Instances Have Torque Above 110
void CheckIfAllTorqueAbove110(const EngineContainer& data);

//Function to Count Instances Over Given Engine Capacity
void CountInstancesOverGivenCapacity(const EngineContainer& data, float cap);

#endif // FUNCTIONALITIES_H
