#include<iostream>
#include"Customer.h"
#include"CustomerType.h"
#include"DebitCard.h"
#include"DebitCardType.h"
#include<memory>

std::shared_ptr<Customer> dummy(){
    std::shared_ptr<Customer> ptr = std::make_shared<Customer>(
        112,
        "Ainz Ooal Gown",
        23,
        CustomerType::REGULAR,
        std::make_shared<DebitCard>(
            102,
            "Ainz",
            "12/30",
            DebitCardType::DOMESTIC
        )
    );
    return ptr;
}

int main(){
    std::shared_ptr<Customer> ans=dummy();
    return 0;
}