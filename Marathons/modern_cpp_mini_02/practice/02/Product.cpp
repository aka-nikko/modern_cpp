#include"Product.h"

Product::Product(std::string id, ProductType type, float price, std::string brand, 
                ProductOrigin origin, float taxamount):
        _productId(id), _productType(type), _productPrice(price), 
        _productBrand(brand), _productOrigin(origin), _productTaxamount(taxamount){}

std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "_productId: " << rhs._productId
       << " _productType: " << static_cast<int>(rhs._productType)
       << " _productPrice: " << rhs._productPrice
       << " _productBrand: " << rhs._productBrand
       << " _productOrigin: " << static_cast<int>(rhs._productOrigin)
       << " _productTaxamount: " << rhs._productTaxamount;
    return os;
}
