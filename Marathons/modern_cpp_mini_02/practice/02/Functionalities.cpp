#include"Functionalities.h"

void CreateObjects(ProductContainer & data){
    data.emplace_back(
        std::make_shared<Product>(
            "101",
            ProductType::FOOD,
            2300000.0f,
            "Asus",
            ProductOrigin::DOMESTIC,
            10000.0f
        )
    );

    data.emplace_back(
        std::make_shared<Product>(
            "102",
            ProductType::FOOD,
            2300000.0f,
            "Asus",
            ProductOrigin::DOMESTIC,
            10000.0f
        )
    );

    data.emplace_back(
        std::make_shared<Product>(
            "103",
            ProductType::FOOD,
            2300000.0f,
            "Asus",
            ProductOrigin::DOMESTIC,
            10000.0f
        )
    );
}

float AverageProductPrice(ProductContainer & data, ProductType type){
    float totalPrice=0.0f;
    for(auto product : data){
        if(product->productType()==type){
            totalPrice=totalPrice+product->productPrice();
        }
    }

    return totalPrice/data.size();
}

float MinimumProductTaxAmount(ProductContainer & data){
    float min=data.front()->productTaxamount();
    auto minimimProduct=data.front();

    for(auto product : data){
        if(product->productTaxamount()<min){
            minimimProduct=product;
        }
    }

    return minimimProduct->productTaxamount();
}

ProductContainer LastNInstancesOfProduct(ProductContainer & data, int n){
    ProductContainer result;
    n = std::min(n, static_cast<int>(data.size()));

    for (auto it = data.rbegin(); it != data.rbegin() + n; ++it) {
        result.push_back(*it);
    }
    return result;
}

std::set<std::string> UniqueBrandNames(ProductContainer & data){
    std::set<std::string> uniqueBrands;

    for(auto product : data){
        uniqueBrands.insert(product->productBrand());
    }

    return uniqueBrands;
}

std::array<int,2> CountOfOriginAndType(ProductContainer & data){

    std::array<int,2> result;
    int typeCount=0;
    int originCount=0;

    for (auto &product : data) {
        if (product->productType()==ProductType::FOOD) {
            typeCount++;
        }
        if (product->productOrigin()==ProductOrigin::DOMESTIC){
            originCount++;
        }
    }

    result.at(0)=typeCount;
    result.at(1)=originCount;

    return result;
}

ProductContainer FindProductsByBrand(ProductContainer &data, std::string &brandName) {
    ProductContainer result;

    for (auto &product : data) {
        if (product->productBrand() == brandName) {
            result.push_back(product);
        }
    }

    return result;
}