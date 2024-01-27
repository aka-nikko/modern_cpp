#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"
#include<vector>
#include<algorithm>
#include<numeric>

using VehiclePointer=std::shared_ptr<Vehicle>;
using Container=std::vector<VehiclePointer>;

using OwnerContainer=std::vector<OwnerPointer>;

//Function to Create Objects
void CreateObject(Container& data, OwnerContainer& owner);

//Function to Search and Display Permit Details by Vehicle ID
void SearchAndDisplayById(const Container &data, int searchId);

//Function to Count Given Vehicle Type by Owner Type 
int CountVehiclesByOwnerType(const Container &data, OwnerType targetType);

//Function to Check if all Prices are Below Given Threshold
bool AreAllPricesBelowThreshold(const Container &data, float threshold);

//Function to Find Permit Issuer State By Owner Name
std::string FindPermitIssuerStateByName(const Container &data, const std::string &ownerName);

//Function to Find Owner Details by Vehicle ID
std::shared_ptr<Owner> FindOwnerDetailsById(const Container &data, int searchId);

//Function to Check if All Permit Issuer States are Same
bool AreAllPermitIssuerStatesSame(const Container &data);

//Function to Dislpay Max and Min Permit Tax
void FindAndDisplayMinMaxPermitTax(const Container &data);

//Function to Find Total Tourist Permit Cost
float FindTotalTouristPermitCost(const Container &data);

#endif // FUNCTIONALITIES_H
