#include"DataModeller.h"

void DataModeller::operator()(){
    if(_goodsPrices.empty()){
        throw std::runtime_error("Data is Empty!");
    }

    float total=0.0f;
    for(float val : _goodsPrices){
        total+=val;
    }

    std::cout<<"Average Value Is: "<<total/_goodsPrices.size()<<std::endl;
}

DataModeller::DataModeller(Vtype instance, const std::vector<float>& goodsPrices):
    _instance(std::move(instance)), _goodsPrices(goodsPrices) {}
    

std::ostream &operator<<(std::ostream &os, const DataModeller &rhs) {
    os << "_instance: ";
    std::visit([&](auto&& instance) {
        os << *instance;
    }, rhs._instance);

    os << "\n_goodsPrices: ";
    for(auto var : rhs._goodsPrices){
        os<<var<<" ";
    }
    return os;
}