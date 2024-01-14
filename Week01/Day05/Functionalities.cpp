#include"Functionalities.h"

void CreateObjects(Container& data) noexcept{
    data.emplace_back(
        std::make_shared<Customer>(
            111,
            "Anshul Verma",
            50,
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
            55,
            CustomerType::REGULAR,
            std::make_shared<DebitCard>(
                102,
                "Momonga",
                "12/30",
                DebitCardType::DOMESTIC
            )
        )
    );
}

float AverageAge(const Container& data) noexcept(false){
    if(data.empty()){
        throw std::runtime_error("Empty Data\n");
    }

    float total=0.0f;

    for(const Pointer& ptr:data){
        total=total+ptr->age();
    }
    
    return total/data.size();
}

Pointer NthCustomer(const Container & data, int N){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }
    if(N>data.size() || N<1){
        throw std::runtime_error("N is Beyond Available Items\n");
    }

    //Method 01
    auto itr=std::next(data.begin(),N-1);
    return *itr;

    //Method 02
    // while(N>1){
    //     itr++;
    //     N--;
    // }
    // return *itr;

    // Method 03
    // return data[N-1];
}

int AgeOfGivenCustomerID(const Container &data, const int id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->id()==id){
            return ptr->age();
        }
    }

    throw std::runtime_error("ID Not Found\n");
}

int CVVOfGivenCustomerID(const Container &data, const int id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->id()==id){
            return ptr->card()->cvv();
        }
    }

    throw std::runtime_error("ID Not Found\n");
}

std::string ExpiryOfGivenCardCVV(const Container &data, const int cvv){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->card()->cvv()==cvv){
            return ptr->card()->expiry();
        }
    }

    throw std::runtime_error("CVV Not Found\n");
}

Container CustomersAgeAbove50(const Container &data){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    Container newdata;
    for(const Pointer& ptr:data){
        if(ptr->age()>50){
            newdata.emplace_back(ptr);
        }
    }
    
    if(newdata.empty()){
        throw std::runtime_error("No Customer Above Age 50\n");
    }
    return newdata;
}

std::shared_ptr<DebitCard> CardOfGivenID(const Container &data, const int id){
    if(data.empty()){
        throw std::runtime_error("Data is Empty\n");
    }

    for(const Pointer& ptr:data){
        if(ptr->id()==id){
            return ptr->card();
        }
    }

    throw std::runtime_error("ID Not Found\n");
}

void DisplayObjects(const Container& data) {
    for (const auto& customer : data) {
        std::cout << *customer << std::endl;
    }
}