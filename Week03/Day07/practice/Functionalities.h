#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"DataModeller.h"

using DataVariant = std::unique_ptr<DataModeller>;
using Container = std::vector<DataVariant>;

void CreateObjects(Container& data);

void CalculateTaxPayable(const Container& data);

void CallParenOperator(const Container& data);

#endif // FUNCTIONALITIES_H
