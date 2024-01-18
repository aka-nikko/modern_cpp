#include"Functionalities.h"

void CreateObjects(Container & data){
    data.emplace_back(
        std::make_shared<Order>(
            "101",
            2000.0f,
            OrderType::PAID,
            200.0f
        )
    );

    data.emplace_back(
        std::make_shared<Order>(
            "102",
            4000.0f,
            OrderType::COD,
            300.0f
        )
    );

    data.emplace_back(
        std::make_shared<Order>(
            "103",
            1000.0f,
            OrderType::PROMOTION,
            50.0f
        )
    );

    data.emplace_back(
        std::make_shared<Order>(
            "104",
            6000.0f,
            OrderType::PAID,
            500.0f
        )
    );

    data.emplace_back(
        std::make_shared<Order>(
            "105",
            3000.0f,
            OrderType::PROMOTION,
            450.0f
        )
    );
}

void DisplayObjects(Container & data){
    for(const auto& order:data){
        std::cout<<*order<<std::endl;
    }
}

std::string HighestDiscountID(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    Pointer temp=data.front();
    for(const auto& order: data){
        if(order->discount()>temp->discount()){
            temp=order;
        }
    }
    return temp->id();
}

OrderType OrderTypeFromID(Container & data, std::string id){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    for(const auto& order: data){
        if(order->id()==id){
            return order->type();
        }
    }

    throw std::runtime_error("Order Not Found!!");
}

float AverageOfValues(Container & data){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    float total=0.0f;
    for(const auto& order: data){
        total=total+(order->value()-order->discount());
    }

    return total/data.size();
}

Container FirstNInstances(Container & data, int N){
    if(data.empty()){
        throw std::runtime_error("Data Is Empty!!");
    }

    if(N>data.size() || N<=0){
        throw std::runtime_error("N is out of Range!!");
    }

    Container newdata;
    auto itr = data.begin();
    while(N>0){
        newdata.emplace_back(*itr);
        itr++;
        N--;
    }

    return newdata;
}