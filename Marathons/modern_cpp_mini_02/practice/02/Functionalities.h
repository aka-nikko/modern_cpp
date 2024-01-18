#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Product.h"
#include<vector>
#include<memory>
#include<array>
#include<set>

using ProductPointer=std::shared_ptr<Product>;
using ProductContainer=std::vector<ProductPointer>;

void CreateObjects(ProductContainer& data);

float AverageProductPrice(ProductContainer& data, ProductType type);

float MinimumProductTaxAmount(ProductContainer& data);

ProductContainer LastNInstancesOfProduct(ProductContainer& data, int n);

std::set<std::string> UniqueBrandNames(ProductContainer& data);

std::array<int,2> CountOfOriginAndType(ProductContainer& data);

ProductContainer FindProductsByBrand(ProductContainer &data, std::string &brandName);

#endif // FUNCTIONALITIES_H
