#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"CabRide.h"
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<array>

using CabPointer=std::shared_ptr<CabRide>;
using CabContainer=std::vector<CabPointer>;

void CreateObjects(CabContainer& data);

PaymentMode ReturnPaymentModeOfGivenCabID(const CabContainer& data, int id);

std::array<PaymentMode, 2> FindMaxMinFarePaymentModes(const CabContainer& data);

std::vector<std::string> GetLastNPickupLocations(const CabContainer& data, int N);

#endif // FUNCTIONALITIES_H
