#include"Functionalities.h"

void CreateObjects(Container& data){
    data.emplace_back(
        std::make_shared<Customer>(
            111,
            "Anshul Verma",
            22,
            CustomerType::ELITE,
            std::make_shared<DebitCard>(
                101, 
                "Nikko", 
                "11/28", 
                DebitCardType::INTERNATIONAL)
        )
    );

    data.emplace_back(
        std::make_shared<Customer>(
            112,
            "Ainz Ooal Gown",
            23,
            CustomerType::REGULAR,
            std::make_shared<DebitCard>(
                102,
                "Ainz",
                "12/30",
                DebitCardType::INTERNATIONAL
            )
        )
    );
}

void DisplayObjects(const Container& data) {
    for (const auto& customer : data) {
        std::cout << *customer << std::endl;
    }
}