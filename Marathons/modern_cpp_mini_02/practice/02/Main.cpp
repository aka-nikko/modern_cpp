#include"Functionalities.h"
#include<functional>

void performOperation(std::function<void(ProductContainer&)> operation, ProductContainer& data) {
    operation(data);
}

int main() {
    ProductContainer mydata;
    CreateObjects(mydata);

    // Displaying all products
    std::cout << "All Products:\n";
    for (const auto& prod : mydata) {
        std::cout << *prod << "\n";
    }

    // Call all the created functions via performOperation
    performOperation([](ProductContainer& data) {
        std::cout << "Average Price of FOOD products: " << AverageProductPrice(data, ProductType::FOOD) << "\n";
    }, mydata);

    performOperation([](ProductContainer& data) {
        std::cout << "Minimum Tax Amount: " << MinimumProductTaxAmount(data) << "\n";
    }, mydata);

    performOperation([](ProductContainer& data) {
        int n = 2;
        ProductContainer lastN = LastNInstancesOfProduct(data, n);
        std::cout << "Last " << n << " instances of products:\n";
        for (const auto& prod : lastN) {
            std::cout << *prod << "\n";
        }
    }, mydata);

    performOperation([](ProductContainer& data) {
        std::set<std::string> uniqueBrands = UniqueBrandNames(data);
        std::cout << "Unique Brand Names:\n";
        for (const auto& brand : uniqueBrands) {
            std::cout << brand << "\n";
        }
    }, mydata);

    performOperation([](ProductContainer& data) {
        std::array<int,2> typeOriginCount = CountOfOriginAndType(data);
        std::cout << "ProductType=FOOD Count:"<<typeOriginCount.at(0)<<std::endl;
        std::cout << "ProductOrigin=DOMESTIC Count:"<<typeOriginCount.at(1)<<std::endl;
    }, mydata);

    std::string brandName = "Asus";
    performOperation([&brandName](ProductContainer& data) {
        ProductContainer byBrand = FindProductsByBrand(data, brandName);
        std::cout << "Products with Brand '" << brandName << "':\n";
        for (const auto& prod : byBrand) {
            std::cout << *prod << "\n";
        }
    }, mydata);

    return 0;
}
